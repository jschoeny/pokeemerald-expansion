#define PH_MOVE(move) move - (MOVES_PH_START + 1)

const struct PlaceholderMove gPlaceholderMoves[MOVES_COUNT_PH] =
{
    [PH_MOVE(MOVE_PH_BITE)] =
    {
        .move =
        {
            MOVE_BITE,          // Normal
            MOVE_BITE,          // Fighting
            MOVE_BITE,          // Flying
            MOVE_POISON_FANG,   // Poison
            MOVE_BITE,          // Ground
            MOVE_BITE,          // Rock
            MOVE_BUG_BITE,      // Bug
            MOVE_LICK,          // Ghost
            MOVE_BITE,          // Steel
            MOVE_BITE,          // Mystery
            MOVE_FIRE_FANG,     // Fire
            MOVE_CLAMP,         // Water
            MOVE_BULLET_SEED,   // Grass
            MOVE_THUNDER_FANG,  // Electric
            MOVE_BITE,          // Psychic
            MOVE_ICE_FANG,      // Ice
            MOVE_BITE,          // Dragon
            MOVE_BITE,          // Dark
            MOVE_BITE           // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_TACKLE)] =
    {
        .move =
        {
            MOVE_TACKLE,        // Normal
            MOVE_ROCK_SMASH,    // Fighting
            MOVE_AERIAL_ACE,    // Flying
            MOVE_POISON_JAB,    // Poison
            MOVE_MUD_SLAP,      // Ground
            MOVE_ROLLOUT,       // Rock
            MOVE_STEAMROLLER,   // Bug
            MOVE_ASTONISH,      // Ghost
            MOVE_IRON_HEAD,     // Steel
            MOVE_TACKLE,        // Mystery
            MOVE_FLAME_WHEEL,   // Fire
            MOVE_AQUA_JET,      // Water
            MOVE_RAZOR_LEAF,    // Grass
            MOVE_SPARK,         // Electric
            MOVE_ZEN_HEADBUTT,  // Psychic
            MOVE_ICE_SHARD,     // Ice
            MOVE_DUAL_CHOP,     // Dragon
            MOVE_FEINT_ATTACK,  // Dark
            MOVE_PLAY_ROUGH     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_ELEMENT_WEAK)] =
    {
        .move =
        {
            MOVE_SONIC_BOOM,    // Normal
            MOVE_VACUUM_WAVE,   // Fighting
            MOVE_GUST,          // Flying
            MOVE_ACID,          // Poison
            MOVE_MUD_SLAP,      // Ground
            MOVE_ROLLOUT,       // Rock
            MOVE_TWINEEDLE,     // Bug
            MOVE_ASTONISH,      // Ghost
            MOVE_THUNDER_SHOCK, // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_EMBER,         // Fire
            MOVE_WATER_GUN,     // Water
            MOVE_ABSORB,        // Grass
            MOVE_SPARK,         // Electric
            MOVE_CONFUSION,     // Psychic
            MOVE_POWDER_SNOW,   // Ice
            MOVE_TWISTER,       // Dragon
            MOVE_PURSUIT,       // Dark
            MOVE_FAIRY_WIND     // Fairy
        }
    }
};
