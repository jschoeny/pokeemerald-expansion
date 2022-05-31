#define MASS_OUTBREAK_LEVEL1 2
#define MASS_OUTBREAK_LEVEL2 3
#define MASS_OUTBREAK_LEVEL3 4
#define MASS_OUTBREAK_LEVEL4 5
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
    // MASS_OUTBREAK_LEVEL1 - 3 badges or less
    {   // 0
        .species = SPECIES_BUDEW,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_LIFE_DEW},
        .level = 6,
        .location = MAP_NUM(ROUTE102),
        .locationGroup = MAP_GROUP(ROUTE102),
        .onWater = FALSE,
        .probability = 50,
        .numEncounters = 15
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

    // MASS_OUTBREAK_LEVEL2 - 5 badges or less
    {   // 2
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_BELLY_DRUM},
        .level = 21,
        .location = MAP_NUM(ROUTE114),
        .locationGroup = MAP_GROUP(ROUTE114),
        .onWater = FALSE,
        .probability = 50,
        .numEncounters = 15
    },

    // MASS_OUTBREAK_LEVEL3 - 7 badges or less
    {   // 3
        .species = SPECIES_MEDITITE,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_DRAIN_PUNCH},
        .level = 31,
        .location = MAP_NUM(MT_PYRE_EXTERIOR),
        .locationGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .onWater = FALSE,
        .probability = 50,
        .numEncounters = 15
    },

    // MASS_OUTBREAK_LEVEL4 - Not yet defeated champion
    {   // 4
        .species = SPECIES_GEODUDE_ALOLAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_MAGNET_RISE},
        .level = 21,
        .location = MAP_NUM(ROUTE114),
        .locationGroup = MAP_GROUP(ROUTE114),
        .onWater = FALSE,
        .probability = 15,
        .numEncounters = 15
    },

    // Defeated champion
    {   // 5
        .species = SPECIES_MAROWAK_ALOLAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_CURSE},
        .level = 31,
        .location = MAP_NUM(ROUTE112),
        .locationGroup = MAP_GROUP(ROUTE112),
        .onWater = FALSE,
        .probability = 10,
        .numEncounters = 5
    },
    {   // 6
        .species = SPECIES_EXEGGUTOR_ALOLAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_GRASSY_TERRAIN},
        .level = 56,
        .location = MAP_NUM(ROUTE104),
        .locationGroup = MAP_GROUP(ROUTE104),
        .onWater = FALSE,
        .probability = 10,
        .numEncounters = 5
    },
    {   // 7
        .species = SPECIES_RAICHU_ALOLAN,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_ALLY_SWITCH},
        .level = 56,
        .location = MAP_NUM(ROUTE104),
        .locationGroup = MAP_GROUP(ROUTE104),
        .onWater = TRUE,
        .probability = 10,
        .numEncounters = 5
    },
    {   // 8
        .species = SPECIES_TREECKO,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_CRUNCH},
        .level = 30,
        .location = MAP_NUM(ROUTE120),
        .locationGroup = MAP_GROUP(ROUTE120),
        .onWater = FALSE,
        .probability = 20,
        .numEncounters = 7
    },
    {   // 9
        .species = SPECIES_TORCHIC,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_BATON_PASS},
        .level = 20,
        .location = MAP_NUM(ROUTE113),
        .locationGroup = MAP_GROUP(ROUTE113),
        .onWater = FALSE,
        .probability = 20,
        .numEncounters = 7
    },
    {   // 10
        .species = SPECIES_MUDKIP,
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_AVALANCHE},
        .level = 17,
        .location = MAP_NUM(ROUTE117),
        .locationGroup = MAP_GROUP(ROUTE117),
        .onWater = FALSE,
        .probability = 20,
        .numEncounters = 7
    }
};

static const u8 NumOutbreakRoutesByBadge[NUM_BADGES + 1] =
{
    4, 5, 6, 7, 11, 18, 20, 26, 37
};
static const u16 OutbreakRoutesByBadge[] =
{
    // No badges
    MAP_ROUTE101, MAP_ROUTE102, MAP_ROUTE103, MAP_ROUTE104,

    // 1 Badge (Rustboro City Gym)
    MAP_ROUTE116,

    // 2 Badges (Dewford Town Gym)
    MAP_ROUTE110,

    // 3 Badges (Mauville City Gym)
    MAP_ROUTE117,

    // 4 Badges (Lavaridge Town Gym)
    MAP_ROUTE112, MAP_ROUTE113, MAP_ROUTE114, MAP_JAGGED_PASS,

    // 5 Badges (Petalburg City Gym)
    MAP_ROUTE111, MAP_ROUTE105, MAP_ROUTE106, MAP_ROUTE107,
    MAP_ROUTE108, MAP_ROUTE109, MAP_ROUTE115,

    // 6 Badges (Fortree City Gym)
    MAP_ROUTE118, MAP_ROUTE119,

    // 7 Badges (Mossdeep City Gym)
    MAP_ROUTE120, MAP_ROUTE121, MAP_ROUTE122, MAP_MT_PYRE_EXTERIOR,
    MAP_MT_PYRE_SUMMIT, MAP_ROUTE124,

    // 8 Badges (Sootopolis City Gym)
    MAP_ROUTE125, MAP_ROUTE126, MAP_ROUTE127, MAP_ROUTE128,
    MAP_ROUTE129, MAP_ROUTE131, MAP_ROUTE132, MAP_ROUTE133,
    MAP_ROUTE134, MAP_UNDERWATER_ROUTE124, MAP_UNDERWATER_ROUTE126,
};
