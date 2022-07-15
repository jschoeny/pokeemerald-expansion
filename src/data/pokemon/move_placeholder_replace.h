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
            MOVE_SKETCH,        // Mystery
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

    [PH_MOVE(MOVE_PH_HEAD)] =
    {
        .move =
        {
            MOVE_HEADBUTT,      // Normal
            MOVE_ROCK_SMASH,    // Fighting
            MOVE_ACROBATICS,    // Flying
            MOVE_POISON_JAB,    // Poison
            MOVE_DRILL_RUN,     // Ground
            MOVE_ACCELEROCK,    // Rock
            MOVE_LUNGE,         // Bug
            MOVE_SHADOW_SNEAK,  // Ghost
            MOVE_IRON_HEAD,     // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLAME_WHEEL,   // Fire
            MOVE_LIQUIDATION,   // Water
            MOVE_GRASSY_GLIDE,  // Grass
            MOVE_SPARK,         // Electric
            MOVE_ZEN_HEADBUTT,  // Psychic
            MOVE_AVALANCHE,     // Ice
            MOVE_DRAGON_HAMMER, // Dragon
            MOVE_PAYBACK,       // Dark
            MOVE_SPIRIT_BREAK   // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BODY)] =
    {
        .move =
        {
            MOVE_BODY_SLAM,     // Normal
            MOVE_BODY_PRESS,    // Fighting
            MOVE_BOUNCE,        // Flying
            MOVE_GUNK_SHOT,     // Poison
            MOVE_HIGH_HORSEPOWER,// Ground
            MOVE_HEAD_SMASH,    // Rock
            MOVE_LUNGE,         // Bug
            MOVE_PHANTOM_FORCE, // Ghost
            MOVE_HEAVY_SLAM,    // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLARE_BLITZ,   // Fire
            MOVE_LIQUIDATION,   // Water
            MOVE_WOOD_HAMMER,   // Grass
            MOVE_WILD_CHARGE,   // Electric
            MOVE_ZEN_HEADBUTT,  // Psychic
            MOVE_ICICLE_CRASH,  // Ice
            MOVE_DRAGON_RUSH,   // Dragon
            MOVE_FOUL_PLAY,     // Dark
            MOVE_PLAY_ROUGH     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_HORN)] =
    {
        .move =
        {
            MOVE_HORN_ATTACK,   // Normal
            MOVE_SACRED_SWORD,  // Fighting
            MOVE_DRILL_PECK,    // Flying
            MOVE_POISON_JAB,    // Poison
            MOVE_BONE_RUSH,     // Ground
            MOVE_STONE_EDGE,    // Rock
            MOVE_MEGAHORN,      // Bug
            MOVE_PHANTOM_FORCE, // Ghost
            MOVE_SMART_STRIKE,  // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLAME_CHARGE,  // Fire
            MOVE_RAZOR_SHELL,   // Water
            MOVE_HORN_LEECH,    // Grass
            MOVE_WILD_CHARGE,   // Electric
            MOVE_PSYCHO_CUT,    // Psychic
            MOVE_ICICLE_SPEAR,  // Ice
            MOVE_DRAGON_HAMMER, // Dragon
            MOVE_KNOCK_OFF,     // Dark
            MOVE_PLAY_ROUGH     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_HEAL_SAP)] =
    {
        .move =
        {
            MOVE_MORNING_SUN,   // Normal
            MOVE_DETECT,        // Fighting
            MOVE_ROOST,         // Flying
            MOVE_ACID_ARMOR,    // Poison
            MOVE_SPIKES,        // Ground
            MOVE_SPIKES,        // Rock
            MOVE_HEAL_ORDER,    // Bug
            MOVE_CURSE,         // Ghost
            MOVE_IRON_DEFENSE,  // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FIRE_SPIN,     // Fire
            MOVE_AQUA_RING,     // Water
            MOVE_LEECH_SEED,    // Grass
            MOVE_CHARGE,        // Electric
            MOVE_AMNESIA,       // Psychic
            MOVE_MIST,          // Ice
            MOVE_DRAGON_DANCE,  // Dragon
            MOVE_FLATTER,       // Dark
            MOVE_SWEET_KISS     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_ELEMENT_WEAK)] =
    {
        .move =
        {
            MOVE_SONIC_BOOM,    // Normal
            MOVE_BULK_UP,       // Fighting
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
            MOVE_THUNDER_SHOCK, // Electric
            MOVE_CONFUSION,     // Psychic
            MOVE_POWDER_SNOW,   // Ice
            MOVE_TWISTER,       // Dragon
            MOVE_PURSUIT,       // Dark
            MOVE_FAIRY_WIND     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_ELEMENT_WEAK2)] =
    {
        .move =
        {
            MOVE_SONIC_BOOM,    // Normal
            MOVE_BULK_UP,       // Fighting
            MOVE_GUST,          // Flying
            MOVE_ACID,          // Poison
            MOVE_MUD_SLAP,      // Ground
            MOVE_ROLLOUT,       // Rock
            MOVE_TWINEEDLE,     // Bug
            MOVE_ASTONISH,      // Ghost
            MOVE_THUNDER_SHOCK, // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_EMBER,         // Fire
            MOVE_BUBBLE,        // Water
            MOVE_ABSORB,        // Grass
            MOVE_THUNDER_SHOCK, // Electric
            MOVE_CONFUSION,     // Psychic
            MOVE_POWDER_SNOW,   // Ice
            MOVE_TWISTER,       // Dragon
            MOVE_PURSUIT,       // Dark
            MOVE_FAIRY_WIND     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_SPATK_ADJACENT1)] =
    {
        .move =
        {
            MOVE_HYPER_VOICE,   // Normal
            MOVE_HYPER_VOICE,   // Fighting
            MOVE_AIR_CUTTER,    // Flying
            MOVE_SLUDGE_WAVE,   // Poison
            MOVE_BULLDOZE,     // Ground
            MOVE_ROCK_SLIDE,    // Rock
            MOVE_STRUGGLE_BUG,  // Bug
            MOVE_EXPANDING_FORCE,// Ghost
            MOVE_DISCHARGE,     // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLAME_BURST,   // Fire
            MOVE_SPARKLING_ARIA,// Water
            MOVE_RAZOR_LEAF,    // Grass
            MOVE_DISCHARGE,     // Electric
            MOVE_EXPANDING_FORCE,// Psychic
            MOVE_ICY_WIND,      // Ice
            MOVE_TWISTER,       // Dragon
            MOVE_SNARL,         // Dark
            MOVE_DISARMING_VOICE// Fairy
        }
    },

    [PH_MOVE(MOVE_PH_SPATK_ADJACENT2)] =
    {
        .move =
        {
            MOVE_BOOMBURST,     // Normal
            MOVE_BOOMBURST,     // Fighting
            MOVE_AIR_CUTTER,    // Flying
            MOVE_SLUDGE_WAVE,   // Poison
            MOVE_EARTHQUAKE,    // Ground
            MOVE_ROCK_SLIDE,    // Rock
            MOVE_STRUGGLE_BUG,  // Bug
            MOVE_EXPANDING_FORCE,// Ghost
            MOVE_DISCHARGE,     // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_HEAT_WAVE,     // Fire
            MOVE_WATER_SPOUT,   // Water
            MOVE_PETAL_BLIZZARD,// Grass
            MOVE_DISCHARGE,     // Electric
            MOVE_EXPANDING_FORCE,// Psychic
            MOVE_BLIZZARD,      // Ice
            MOVE_CLANGING_SCALES,// Dragon
            MOVE_SNARL,         // Dark
            MOVE_DAZZLING_GLEAM // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_FEET_MULTIHIT_FIXED)] =
    {
        .move =
        {
            MOVE_DOUBLE_HIT,    // Normal
            MOVE_DOUBLE_KICK,   // Fighting
            MOVE_DUAL_WINGBEAT, // Flying
            MOVE_DOUBLE_HIT,    // Poison
            MOVE_ROCK_BLAST,    // Ground
            MOVE_ROCK_BLAST,    // Rock
            MOVE_TWINEEDLE,     // Bug
            MOVE_DOUBLE_HIT,    // Ghost
            MOVE_DOUBLE_HIT,    // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_DOUBLE_HIT,    // Fire
            MOVE_DOUBLE_HIT,    // Water
            MOVE_DOUBLE_HIT,    // Grass
            MOVE_DOUBLE_HIT,    // Electric
            MOVE_DOUBLE_HIT,    // Psychic
            MOVE_ICICLE_SPEAR,  // Ice
            MOVE_DUAL_CHOP,     // Dragon
            MOVE_DOUBLE_HIT,    // Dark
            MOVE_DOUBLE_HIT     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BEAM1)] =
    {
        .move =
        {
            MOVE_TRI_ATTACK,    // Normal
            MOVE_AURA_SPHERE,   // Fighting
            MOVE_AIR_SLASH,     // Flying
            MOVE_SLUDGE_BOMB,   // Poison
            MOVE_MUD_SHOT,      // Ground
            MOVE_POWER_GEM,     // Rock
            MOVE_SILVER_WIND,   // Bug
            MOVE_OMINOUS_WIND,  // Ghost
            MOVE_MIRROR_SHOT,   // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLAMETHROWER,  // Fire
            MOVE_WATER_PULSE,   // Water
            MOVE_MEGA_DRAIN,    // Grass
            MOVE_THUNDERBOLT,   // Electric
            MOVE_PSYBEAM,       // Psychic
            MOVE_AURORA_BEAM,   // Ice
            MOVE_DRAGON_BREATH, // Dragon
            MOVE_DARK_PULSE,    // Dark
            MOVE_MOONBLAST      // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BEAM2)] =
    {
        .move =
        {
            MOVE_TRI_ATTACK,    // Normal
            MOVE_AURA_SPHERE,   // Fighting
            MOVE_AIR_SLASH,     // Flying
            MOVE_SLUDGE_BOMB,   // Poison
            MOVE_MUD_BOMB,      // Ground
            MOVE_POWER_GEM,     // Rock
            MOVE_SIGNAL_BEAM,   // Bug
            MOVE_SHADOW_BALL,   // Ghost
            MOVE_FLASH_CANNON,  // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLAMETHROWER,  // Fire
            MOVE_BUBBLE_BEAM,   // Water
            MOVE_GIGA_DRAIN,    // Grass
            MOVE_THUNDERBOLT,   // Electric
            MOVE_PSYCHIC,       // Psychic
            MOVE_ICE_BEAM,      // Ice
            MOVE_DRAGON_PULSE,  // Dragon
            MOVE_DARK_PULSE,    // Dark
            MOVE_MOONBLAST      // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BEAM3)] =
    {
        .move =
        {
            MOVE_HYPER_BEAM,    // Normal
            MOVE_FOCUS_BLAST,   // Fighting
            MOVE_HURRICANE,     // Flying
            MOVE_SLUDGE_BOMB,   // Poison
            MOVE_METEOR_BEAM,   // Ground
            MOVE_METEOR_BEAM,   // Rock
            MOVE_BUG_BUZZ,      // Bug
            MOVE_SHADOW_BALL,   // Ghost
            MOVE_STEEL_BEAM,    // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FIRE_BLAST,    // Fire
            MOVE_HYDRO_PUMP,    // Water
            MOVE_LEAF_STORM,    // Grass
            MOVE_THUNDER,       // Electric
            MOVE_FUTURE_SIGHT,  // Psychic
            MOVE_BLIZZARD,      // Ice
            MOVE_DRACO_METEOR,  // Dragon
            MOVE_DARK_PULSE,    // Dark
            MOVE_MOONBLAST      // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BEAM4)] =
    {
        .move =
        {
            MOVE_HYPER_BEAM,    // Normal
            MOVE_FOCUS_BLAST,   // Fighting
            MOVE_HURRICANE,     // Flying
            MOVE_SLUDGE_BOMB,   // Poison
            MOVE_METEOR_BEAM,   // Ground
            MOVE_METEOR_BEAM,   // Rock
            MOVE_POLLEN_PUFF,   // Bug
            MOVE_SHADOW_BALL,   // Ghost
            MOVE_STEEL_BEAM,    // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FIRE_BLAST,    // Fire
            MOVE_HYDRO_PUMP,    // Water
            MOVE_SOLAR_BEAM,    // Grass
            MOVE_THUNDER,       // Electric
            MOVE_FUTURE_SIGHT,  // Psychic
            MOVE_BLIZZARD,      // Ice
            MOVE_DRACO_METEOR,  // Dragon
            MOVE_DARK_PULSE,    // Dark
            MOVE_MOONBLAST      // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BALL)] =
    {
        .move =
        {
            MOVE_RAZOR_WIND,    // Normal
            MOVE_AURA_SPHERE,   // Fighting
            MOVE_AIR_CUTTER,    // Flying
            MOVE_SLUDGE_BOMB,   // Poison
            MOVE_MUD_BOMB,      // Ground
            MOVE_MUD_BOMB,      // Rock
            MOVE_SIGNAL_BEAM,   // Bug
            MOVE_SHADOW_BALL,   // Ghost
            MOVE_STEEL_BEAM,    // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_MYSTICAL_FIRE, // Fire
            MOVE_WATER_PULSE,   // Water
            MOVE_ENERGY_BALL,   // Grass
            MOVE_ELECTRO_BALL,  // Electric
            MOVE_EXTRASENSORY,  // Psychic
            MOVE_FROST_BREATH,  // Ice
            MOVE_DRAGON_PULSE,  // Dragon
            MOVE_DARK_PULSE,    // Dark
            MOVE_MOONBLAST      // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BODY_ATK_SPEED)] =
    {
        .move =
        {
            MOVE_EXTREME_SPEED, // Normal
            MOVE_EXTREME_SPEED, // Fighting
            MOVE_EXTREME_SPEED, // Flying
            MOVE_EXTREME_SPEED, // Poison
            MOVE_BULLDOZE,      // Ground
            MOVE_ACCELEROCK,    // Rock
            MOVE_EXTREME_SPEED, // Bug
            MOVE_SHADOW_SNEAK,  // Ghost
            MOVE_EXTREME_SPEED, // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLAME_CHARGE,  // Fire
            MOVE_AQUA_JET,      // Water
            MOVE_GRASSY_GLIDE,  // Grass
            MOVE_WILD_CHARGE,   // Electric
            MOVE_ZEN_HEADBUTT,  // Psychic
            MOVE_ICE_SHARD,     // Ice
            MOVE_DRAGON_RUSH,   // Dragon
            MOVE_NIGHT_SLASH,   // Dark
            MOVE_EXTREME_SPEED  // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BLADE)] =
    {
        .move =
        {
            MOVE_SLASH,         // Normal
            MOVE_SLASH,         // Fighting
            MOVE_AERIAL_ACE,    // Flying
            MOVE_CROSS_POISON,  // Poison
            MOVE_BONE_CLUB,     // Ground
            MOVE_BONE_CLUB,     // Rock
            MOVE_X_SCISSOR,     // Bug
            MOVE_SHADOW_CLAW,   // Ghost
            MOVE_STEEL_WING,    // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FIRE_LASH,     // Fire
            MOVE_RAZOR_SHELL,   // Water
            MOVE_LEAF_BLADE,    // Grass
            MOVE_SPARK,         // Electric
            MOVE_PSYCHO_CUT,    // Psychic
            MOVE_ICICLE_SPEAR,  // Ice
            MOVE_DRAGON_CLAW,   // Dragon
            MOVE_NIGHT_SLASH,   // Dark
            MOVE_PLAY_ROUGH     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_FIST)] =
    {
        .move =
        {
            MOVE_MEGA_PUNCH,    // Normal
            MOVE_POWER_UP_PUNCH,// Fighting
            MOVE_MEGA_PUNCH,    // Flying
            MOVE_POISON_JAB,    // Poison
            MOVE_MEGA_PUNCH,    // Ground
            MOVE_SMACK_DOWN,    // Rock
            MOVE_SKITTER_SMACK, // Bug
            MOVE_SHADOW_PUNCH,  // Ghost
            MOVE_BULLET_PUNCH,  // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FIRE_PUNCH,    // Fire
            MOVE_CRABHAMMER,    // Water
            MOVE_NEEDLE_ARM,    // Grass
            MOVE_THUNDER_PUNCH, // Electric
            MOVE_HEART_STAMP,   // Psychic
            MOVE_ICE_PUNCH,     // Ice
            MOVE_DUAL_CHOP,     // Dragon
            MOVE_SUCKER_PUNCH,  // Dark
            MOVE_PLAY_ROUGH     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_KICK)] =
    {
        .move =
        {
            MOVE_MEGA_KICK,     // Normal
            MOVE_JUMP_KICK,     // Fighting
            MOVE_BRAVE_BIRD,    // Flying
            MOVE_POISON_JAB,    // Poison
            MOVE_HIGH_HORSEPOWER,// Ground
            MOVE_HIGH_HORSEPOWER,// Rock
            MOVE_LUNGE,         // Bug
            MOVE_PHANTOM_FORCE, // Ghost
            MOVE_MEGA_KICK,     // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_BLAZE_KICK,    // Fire
            MOVE_CRABHAMMER,    // Water
            MOVE_TROP_KICK,     // Grass
            MOVE_WILD_CHARGE,   // Electric
            MOVE_HEART_STAMP,   // Psychic
            MOVE_ICICLE_CRASH,  // Ice
            MOVE_DRAGON_HAMMER, // Dragon
            MOVE_THROAT_CHOP,   // Dark
            MOVE_PLAY_ROUGH     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BODY_RECOIL)] =
    {
        .move =
        {
            MOVE_TAKE_DOWN,     // Normal
            MOVE_TAKE_DOWN,     // Fighting
            MOVE_BRAVE_BIRD,    // Flying
            MOVE_TAKE_DOWN,     // Poison
            MOVE_HEAD_SMASH,    // Ground
            MOVE_HEAD_SMASH,    // Rock
            MOVE_TAKE_DOWN,     // Bug
            MOVE_TAKE_DOWN,     // Ghost
            MOVE_TAKE_DOWN,     // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLARE_BLITZ,   // Fire
            MOVE_LIQUIDATION,   // Water
            MOVE_WOOD_HAMMER,   // Grass
            MOVE_WILD_CHARGE,   // Electric
            MOVE_TAKE_DOWN,     // Psychic
            MOVE_ICE_BALL,      // Ice
            MOVE_SCALE_SHOT,    // Dragon
            MOVE_TAKE_DOWN,     // Dark
            MOVE_PLAY_ROUGH     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_HAZARD)] =
    {
        .move =
        {
            MOVE_PERISH_SONG,   // Normal
            MOVE_SPIKES,        // Fighting
            MOVE_DEFOG,         // Flying
            MOVE_TOXIC_SPIKES,  // Poison
            MOVE_SPIKES,        // Ground
            MOVE_STEALTH_ROCK,  // Rock
            MOVE_STICKY_WEB,    // Bug
            MOVE_DESTINY_BOND,  // Ghost
            MOVE_SPIKES,        // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FIRE_SPIN,     // Fire
            MOVE_WHIRLPOOL,     // Water
            MOVE_GRASSY_TERRAIN,// Grass
            MOVE_ELECTRIC_TERRAIN,// Electric
            MOVE_PSYCHIC_TERRAIN,// Psychic
            MOVE_MIST,          // Ice
            MOVE_SPIKES,        // Dragon
            MOVE_TORMENT,       // Dark
            MOVE_MISTY_TERRAIN  // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_WEATHER)] =
    {
        .move =
        {
            MOVE_WEATHER_BALL,  // Normal
            MOVE_SPIKES,        // Fighting
            MOVE_TAILWIND,      // Flying
            MOVE_TOXIC_SPIKES,  // Poison
            MOVE_SANDSTORM,     // Ground
            MOVE_SANDSTORM,     // Rock
            MOVE_STICKY_WEB,    // Bug
            MOVE_DESTINY_BOND,  // Ghost
            MOVE_SANDSTORM,     // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_SUNNY_DAY,     // Fire
            MOVE_RAIN_DANCE,    // Water
            MOVE_SUNNY_DAY,     // Grass
            MOVE_RAIN_DANCE,    // Electric
            MOVE_GRAVITY,       // Psychic
            MOVE_HAIL,          // Ice
            MOVE_WEATHER_BALL,  // Dragon
            MOVE_TORMENT,       // Dark
            MOVE_MISTY_TERRAIN  // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_TYPE_EFF)] =
    {
        .move =
        {
            MOVE_ODOR_SLEUTH,   // Normal
            MOVE_ODOR_SLEUTH,   // Fighting
            MOVE_MIRROR_MOVE,   // Flying
            MOVE_GASTRO_ACID,   // Poison
            MOVE_MUD_SPORT,     // Ground
            MOVE_TAR_SHOT,      // Rock
            MOVE_POWDER,        // Bug
            MOVE_GRAVITY,       // Ghost
            MOVE_IRON_DEFENSE,  // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_SUNNY_DAY,     // Fire
            MOVE_WATER_SPORT,   // Water
            MOVE_WORRY_SEED,    // Grass
            MOVE_ION_DELUGE,    // Electric
            MOVE_MIRACLE_EYE,   // Psychic
            MOVE_HAIL,          // Ice
            MOVE_SAFEGUARD,     // Dragon
            MOVE_SAFEGUARD,     // Dark
            MOVE_GRAVITY        // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_SPATK_ADJACENT1_MUD)] =
    {
        .move =
        {
            MOVE_HYPER_VOICE,   // Normal
            MOVE_HYPER_VOICE,   // Fighting
            MOVE_AIR_CUTTER,    // Flying
            MOVE_SLUDGE_WAVE,   // Poison
            MOVE_BULLDOZE,      // Ground
            MOVE_ROCK_SLIDE,    // Rock
            MOVE_STRUGGLE_BUG,  // Bug
            MOVE_EXPANDING_FORCE,// Ghost
            MOVE_DISCHARGE,     // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLAME_BURST,   // Fire
            MOVE_MUDDY_WATER,   // Water
            MOVE_RAZOR_LEAF,    // Grass
            MOVE_DISCHARGE,     // Electric
            MOVE_EXPANDING_FORCE,// Psychic
            MOVE_ICY_WIND,      // Ice
            MOVE_TWISTER,       // Dragon
            MOVE_SNARL,         // Dark
            MOVE_DISARMING_VOICE// Fairy
        }
    },

    [PH_MOVE(MOVE_PH_RECOVER)] =
    {
        .move =
        {
            MOVE_RECOVER,       // Normal
            MOVE_RECOVER,       // Fighting
            MOVE_ROOST,         // Flying
            MOVE_RECOVER,       // Poison
            MOVE_RECOVER,       // Ground
            MOVE_RECOVER,       // Rock
            MOVE_HEAL_ORDER,    // Bug
            MOVE_CURSE,         // Ghost
            MOVE_RECOVER,       // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_MORNING_SUN,   // Fire
            MOVE_AQUA_RING,     // Water
            MOVE_SYNTHESIS,     // Grass
            MOVE_RECOVER,       // Electric
            MOVE_MORNING_SUN,   // Psychic
            MOVE_RECOVER,       // Ice
            MOVE_RECOVER,       // Dragon
            MOVE_MOONLIGHT,     // Dark
            MOVE_MOONLIGHT      // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_RECOVER2)] =
    {
        .move =
        {
            MOVE_RECOVER,       // Normal
            MOVE_RECOVER,       // Fighting
            MOVE_ROOST,         // Flying
            MOVE_RECOVER,       // Poison
            MOVE_RECOVER,       // Ground
            MOVE_RECOVER,       // Rock
            MOVE_HEAL_ORDER,    // Bug
            MOVE_CURSE,         // Ghost
            MOVE_RECOVER,       // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_MORNING_SUN,   // Fire
            MOVE_AQUA_RING,     // Water
            MOVE_INGRAIN,       // Grass
            MOVE_RECOVER,       // Electric
            MOVE_MORNING_SUN,   // Psychic
            MOVE_RECOVER,       // Ice
            MOVE_RECOVER,       // Dragon
            MOVE_MOONLIGHT,     // Dark
            MOVE_MOONLIGHT      // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_STRONGWIND)] =
    {
        .move =
        {
            MOVE_RAZOR_WIND,    // Normal
            MOVE_RAZOR_WIND,    // Fighting
            MOVE_HURRICANE,     // Flying
            MOVE_RAZOR_WIND,    // Poison
            MOVE_RAZOR_WIND,    // Ground
            MOVE_RAZOR_WIND,    // Rock
            MOVE_SILVER_WIND,   // Bug
            MOVE_OMINOUS_WIND,  // Ghost
            MOVE_RAZOR_WIND,    // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_HEAT_WAVE,     // Fire
            MOVE_SURF,          // Water
            MOVE_LEAF_TORNADO,  // Grass
            MOVE_DISCHARGE,     // Electric
            MOVE_RAZOR_WIND,    // Psychic
            MOVE_ICY_WIND,      // Ice
            MOVE_RAZOR_WIND,    // Dragon
            MOVE_RAZOR_WIND,    // Dark
            MOVE_RAZOR_WIND     // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_THRASH)] =
    {
        .move =
        {
            MOVE_THRASH,        // Normal
            MOVE_SUPERPOWER,    // Fighting
            MOVE_SKY_ATTACK,    // Flying
            MOVE_GUNK_SHOT,     // Poison
            MOVE_EARTHQUAKE,    // Ground
            MOVE_ROCK_WRECKER,  // Rock
            MOVE_MEGAHORN,      // Bug
            MOVE_POLTERGEIST,   // Ghost
            MOVE_STEEL_ROLLER,  // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_OVERHEAT,      // Fire
            MOVE_WATER_SPOUT,   // Water
            MOVE_PETAL_DANCE,   // Grass
            MOVE_VOLT_TACKLE,   // Electric
            MOVE_FUTURE_SIGHT,  // Psychic
            MOVE_ICE_HAMMER,    // Ice
            MOVE_OUTRAGE,       // Dragon
            MOVE_FOUL_PLAY,     // Dark
            MOVE_MISTY_EXPLOSION // Fairy
        }
    },

    [PH_MOVE(MOVE_PH_BODY_2TURN)] =
    {
        .move =
        {
            MOVE_SLAM,          // Normal
            MOVE_SUBMISSION,    // Fighting
            MOVE_FLY,           // Flying
            MOVE_GUNK_SHOT,     // Poison
            MOVE_DIG,           // Ground
            MOVE_METEOR_BEAM,   // Rock
            MOVE_LUNGE,         // Bug
            MOVE_PHANTOM_FORCE, // Ghost
            MOVE_HEAVY_SLAM,    // Steel
            MOVE_SKETCH,        // Mystery
            MOVE_FLARE_BLITZ,   // Fire
            MOVE_DIVE,          // Water
            MOVE_SOLAR_BLADE,   // Grass
            MOVE_VOLT_TACKLE,   // Electric
            MOVE_ZEN_HEADBUTT,  // Psychic
            MOVE_ICICLE_CRASH,  // Ice
            MOVE_DRAGON_RUSH,   // Dragon
            MOVE_FOUL_PLAY,     // Dark
            MOVE_PLAY_ROUGH     // Fairy
        }
    }
};
