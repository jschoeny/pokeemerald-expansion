#define MASS_OUTBREAK_LEVEL1 6
#define MASS_OUTBREAK_LEVEL2 12
#define MASS_OUTBREAK_LEVEL3 18
#define MASS_OUTBREAK_LEVEL4 27
static const struct {
    u16 species;
    u16 moves[MAX_MON_MOVES];
    u8 level;
    u8 location;
    u8 locationGroup;
    bool8 onWater;
    u8 probability;
    u8 numEncounters;
} sPokeOutbreakSpeciesList[] = {
    // MASS_OUTBREAK_LEVEL1 - 0-4 badges
    {   // 0
        .species = SPECIES_BUDEW,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_LIFE_DEW},
        .level = 6,
        .location = MAP_NUM(ROUTE102),
        .locationGroup = MAP_GROUP(ROUTE102),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 12
    },
    {   // 1
        .species = SPECIES_SURSKIT,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_BUG_BITE},
        .level = 6,
        .location = MAP_NUM(ROUTE102),
        .locationGroup = MAP_GROUP(ROUTE102),
        .onWater = FALSE,
        .probability = 50,
        .numEncounters = 15
    },
    {   // 2
        .species = SPECIES_FLETCHLING,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_SWORDS_DANCE},
        .level = 9,
        .location = MAP_NUM(ROUTE116),
        .locationGroup = MAP_GROUP(ROUTE116),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 10
    },
    {   // 3
        .species = SPECIES_COTTONEE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_U_TURN},
        .level = 6,
        .location = MAP_NUM(PETALBURG_WOODS),
        .locationGroup = MAP_GROUP(PETALBURG_WOODS),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 10
    },
    {   // 4
        .species = SPECIES_SHELLOS,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_CLEAR_SMOG},
        .level = 16,
        .location = MAP_NUM(ROUTE110),
        .locationGroup = MAP_GROUP(ROUTE110),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 10
    },
    {   // 5
        .species = SPECIES_EEVEE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_WISH},
        .level = 9,
        .location = MAP_NUM(ROUTE116),
        .locationGroup = MAP_GROUP(ROUTE116),
        .onWater = FALSE,
        .probability = 20,
        .numEncounters = 7
    },

    // MASS_OUTBREAK_LEVEL2 - 5-6 badges
    {   // 6
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_BELLY_DRUM},
        .level = 21,
        .location = MAP_NUM(ROUTE114),
        .locationGroup = MAP_GROUP(ROUTE114),
        .onWater = FALSE,
        .probability = 50,
        .numEncounters = 15
    },
    {   // 7
        .species = SPECIES_BUNEARY,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_SWITCHEROO},
        .level = 7,
        .location = MAP_NUM(ROUTE104),
        .locationGroup = MAP_GROUP(ROUTE104),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 10
    },
    {   // 8
        .species = SPECIES_MURKROW,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_BRAVE_BIRD},
        .level = 16,
        .location = MAP_NUM(ROUTE110),
        .locationGroup = MAP_GROUP(ROUTE110),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 10
    },
    {   // 9
        .species = SPECIES_FLETCHINDER,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_SWORDS_DANCE},
        .level = 20,
        .location = MAP_NUM(ROUTE114),
        .locationGroup = MAP_GROUP(ROUTE114),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 10
    },
    {   // 10
        .species = SPECIES_LARVESTA,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_WILD_CHARGE},
        .level = 18,
        .location = MAP_NUM(ROUTE112),
        .locationGroup = MAP_GROUP(ROUTE112),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 10
    },
    {   // 11
        .species = SPECIES_TYROGUE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_BULLET_PUNCH},
        .level = 17,
        .location = MAP_NUM(ROUTE112),
        .locationGroup = MAP_GROUP(ROUTE112),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 10
    },

    // MASS_OUTBREAK_LEVEL3 - 7 badges
    {   // 12
        .species = SPECIES_MEDITITE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_DRAIN_PUNCH},
        .level = 31,
        .location = MAP_NUM(MT_PYRE_EXTERIOR),
        .locationGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .onWater = FALSE,
        .probability = 50,
        .numEncounters = 15
    },
    {   // 13
        .species = SPECIES_TREECKO,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_CRUNCH},
        .level = 30,
        .location = MAP_NUM(ROUTE120),
        .locationGroup = MAP_GROUP(ROUTE120),
        .onWater = FALSE,
        .probability = 20,
        .numEncounters = 7
    },
    {   // 14
        .species = SPECIES_TORCHIC,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_BATON_PASS},
        .level = 20,
        .location = MAP_NUM(ROUTE113),
        .locationGroup = MAP_GROUP(ROUTE113),
        .onWater = FALSE,
        .probability = 20,
        .numEncounters = 7
    },
    {   // 15
        .species = SPECIES_MUDKIP,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_AVALANCHE},
        .level = 17,
        .location = MAP_NUM(ROUTE117),
        .locationGroup = MAP_GROUP(ROUTE117),
        .onWater = FALSE,
        .probability = 20,
        .numEncounters = 7
    },
    {   // 16
        .species = SPECIES_ROTOM,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_RISING_VOLTAGE},
        .level = 31,
        .location = MAP_NUM(ROUTE123),
        .locationGroup = MAP_GROUP(ROUTE123),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 7
    },
    {   // 17
        .species = SPECIES_RIOLU,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_VACUUM_WAVE},
        .level = 19,
        .location = MAP_NUM(ROUTE112),
        .locationGroup = MAP_GROUP(ROUTE112),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 7
    },

    // MASS_OUTBREAK_LEVEL4 - 8 badges
    {   // 18
        .species = SPECIES_GEODUDE_ALOLAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_MAGNET_RISE},
        .level = 21,
        .location = MAP_NUM(ROUTE114),
        .locationGroup = MAP_GROUP(ROUTE114),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 15
    },
    {   // 19
        .species = SPECIES_SANDILE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_STEALTH_ROCK},
        .level = 21,
        .location = MAP_NUM(ROUTE111),
        .locationGroup = MAP_GROUP(ROUTE111),
        .onWater = FALSE,
        .probability = 30,
        .numEncounters = 15
    },
    {   // 20
        .species = SPECIES_BELDUM,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_STEALTH_ROCK},
        .level = 21,
        .location = MAP_NUM(METEOR_FALLS_B1F_2R),
        .locationGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 7
    },
    {   // 21
        .species = SPECIES_ZIGZAGOON_GALARIAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_CLOSE_COMBAT},
        .level = 6,
        .location = MAP_NUM(PETALBURG_WOODS),
        .locationGroup = MAP_GROUP(PETALBURG_WOODS),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 15
    },
    {   // 22
        .species = SPECIES_AIPOM,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_U_TURN},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 12
    },
    {   // 23
        .species = SPECIES_LAMPENT,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_SUBSTITUTE},
        .level = 30,
        .location = MAP_NUM(MT_PYRE_EXTERIOR),
        .locationGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 12
    },
    {   // 24
        .species = SPECIES_HAKAMO_O,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_STEALTH_ROCK},
        .level = 35,
        .location = MAP_NUM(METEOR_FALLS_B1F_2R),
        .locationGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 10
    },
    {   // 25
        .species = SPECIES_CORSOLA_GALARIAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_METEOR_BEAM},
        .level = 30,
        .location = MAP_NUM(ROUTE127),
        .locationGroup = MAP_GROUP(ROUTE127),
        .onWater = TRUE,
        .probability = 15,
        .numEncounters = 10
    },
    {   // 26
        .species = SPECIES_MIMIKYU,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_SWORDS_DANCE},
        .level = 27,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 7
    },

    // Defeated champion
    {   // 24
        .species = SPECIES_MAROWAK_ALOLAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_CURSE},
        .level = 31,
        .location = MAP_NUM(ROUTE112),
        .locationGroup = MAP_GROUP(ROUTE112),
        .onWater = FALSE,
        .probability = 10,
        .numEncounters = 5
    },
    {   // 25
        .species = SPECIES_EXEGGUTOR_ALOLAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_GRASSY_TERRAIN},
        .level = 56,
        .location = MAP_NUM(ROUTE104),
        .locationGroup = MAP_GROUP(ROUTE104),
        .onWater = FALSE,
        .probability = 10,
        .numEncounters = 5
    },
    {   // 26
        .species = SPECIES_RAICHU_ALOLAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_ALLY_SWITCH},
        .level = 56,
        .location = MAP_NUM(ROUTE105),
        .locationGroup = MAP_GROUP(ROUTE105),
        .onWater = TRUE,
        .probability = 10,
        .numEncounters = 5
    },
    {   // 27
        .species = SPECIES_BULBASAUR,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_WEATHER_BALL},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 28
        .species = SPECIES_CHARMANDER,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_DRAGON_DANCE},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 29
        .species = SPECIES_SQUIRTLE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_SHELL_SMASH},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 30
        .species = SPECIES_TURTWIG,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_STEALTH_ROCK},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 31
        .species = SPECIES_CHIMCHAR,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_U_TURN},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 32
        .species = SPECIES_PIPLUP,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_DEFOG},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 33
        .species = SPECIES_SNIVY,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_GLARE},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 34
        .species = SPECIES_TEPIG,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_WILD_CHARGE},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 35
        .species = SPECIES_OSHAWOTT,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_GRASS_KNOT},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 36
        .species = SPECIES_CHESPIN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_DRAIN_PUNCH},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 37
        .species = SPECIES_FENNEKIN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_GRASS_KNOT},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    },
    {   // 38
        .species = SPECIES_FROAKIE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_GUNK_SHOT},
        .level = 10,
        .location = MAP_NUM(ROUTE121),
        .locationGroup = MAP_GROUP(ROUTE121),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 5
    }
};

static const u8 NumOutbreakRoutesByBadge[NUM_BADGES + 1] =
{
    5, 6, 9, 10, 15, 24, 26, 33, 47
};
static const u16 OutbreakRoutesByBadge[] =
{
    // No badges
    MAP_ROUTE101, MAP_ROUTE102, MAP_ROUTE103, MAP_ROUTE104,
    MAP_PETALBURG_WOODS,

    // 1 Badge (Rustboro City Gym)
    MAP_ROUTE116,

    // 2 Badges (Dewford Town Gym)
    MAP_ROUTE110, MAP_GRANITE_CAVE_1F, MAP_GRANITE_CAVE_B1F,

    // 3 Badges (Mauville City Gym)
    MAP_ROUTE117,

    // 4 Badges (Lavaridge Town Gym)
    MAP_ROUTE112, MAP_ROUTE113, MAP_ROUTE114, MAP_JAGGED_PASS,
    MAP_FIERY_PATH,

    // 5 Badges (Petalburg City Gym)
    MAP_ROUTE111, MAP_ROUTE105, MAP_ROUTE106, MAP_ROUTE107,
    MAP_ROUTE108, MAP_ROUTE109, MAP_ROUTE115, MAP_METEOR_FALLS_1F_1R,
    MAP_METEOR_FALLS_B1F_2R,

    // 6 Badges (Fortree City Gym)
    MAP_ROUTE118, MAP_ROUTE119,

    // 7 Badges (Mossdeep City Gym)
    MAP_ROUTE120, MAP_ROUTE121, MAP_ROUTE122, MAP_MT_PYRE_EXTERIOR,
    MAP_MT_PYRE_SUMMIT, MAP_ROUTE123, MAP_ROUTE124,

    // 8 Badges (Sootopolis City Gym)
    MAP_ROUTE125, MAP_ROUTE126, MAP_ROUTE127, MAP_ROUTE128,
    MAP_ROUTE129, MAP_ROUTE131, MAP_ROUTE132, MAP_ROUTE133,
    MAP_ROUTE134, MAP_UNDERWATER_ROUTE124, MAP_UNDERWATER_ROUTE126,
    MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM,
    MAP_VICTORY_ROAD_B1F, MAP_VICTORY_ROAD_B2F
};
