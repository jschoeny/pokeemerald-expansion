#define PH_MOVE(move) move - (MOVES_PH_START + 1)

const struct PlaceholderMove gPlaceholderMoves[MOVES_COUNT_PH] =
{
    [PH_MOVE(MOVE_PH_BITE)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_BITE,
            [TYPE_FIGHTING] = MOVE_BITE,
            [TYPE_FLYING]   = MOVE_BITE,
            [TYPE_POISON]   = MOVE_POISON_FANG,
            [TYPE_GROUND]   = MOVE_BITE,
            [TYPE_ROCK]     = MOVE_BITE,
            [TYPE_BUG]      = MOVE_BUG_BITE,
            [TYPE_GHOST]    = MOVE_LICK,
            [TYPE_STEEL]    = MOVE_BITE,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_FANG,
            [TYPE_WATER]    = MOVE_CLAMP,
            [TYPE_GRASS]    = MOVE_BULLET_SEED,
            [TYPE_ELECTRIC] = MOVE_THUNDER_FANG,
            [TYPE_PSYCHIC]  = MOVE_BITE,
            [TYPE_ICE]      = MOVE_ICE_FANG,
            [TYPE_DRAGON]   = MOVE_BITE,
            [TYPE_DARK]     = MOVE_BITE,
            [TYPE_FAIRY]    = MOVE_BITE
        }
    },

    [PH_MOVE(MOVE_PH_HEAD)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_HEADBUTT,
            [TYPE_FIGHTING] = MOVE_ROCK_SMASH,
            [TYPE_FLYING]   = MOVE_ACROBATICS,
            [TYPE_POISON]   = MOVE_POISON_JAB,
            [TYPE_GROUND]   = MOVE_DRILL_RUN,
            [TYPE_ROCK]     = MOVE_ACCELEROCK,
            [TYPE_BUG]      = MOVE_LUNGE,
            [TYPE_GHOST]    = MOVE_SHADOW_SNEAK,
            [TYPE_STEEL]    = MOVE_IRON_HEAD,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAME_WHEEL,
            [TYPE_WATER]    = MOVE_LIQUIDATION,
            [TYPE_GRASS]    = MOVE_GRASSY_GLIDE,
            [TYPE_ELECTRIC] = MOVE_SPARK,
            [TYPE_PSYCHIC]  = MOVE_ZEN_HEADBUTT,
            [TYPE_ICE]      = MOVE_AVALANCHE,
            [TYPE_DRAGON]   = MOVE_DRAGON_HAMMER,
            [TYPE_DARK]     = MOVE_PAYBACK,
            [TYPE_FAIRY]    = MOVE_SPIRIT_BREAK
        }
    },

    [PH_MOVE(MOVE_PH_BODY)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_BODY_SLAM,
            [TYPE_FIGHTING] = MOVE_BODY_PRESS,
            [TYPE_FLYING]   = MOVE_BOUNCE,
            [TYPE_POISON]   = MOVE_GUNK_SHOT,
            [TYPE_GROUND]   = MOVE_HIGH_HORSEPOWER,
            [TYPE_ROCK]     = MOVE_HEAD_SMASH,
            [TYPE_BUG]      = MOVE_LUNGE,
            [TYPE_GHOST]    = MOVE_PHANTOM_FORCE,
            [TYPE_STEEL]    = MOVE_HEAVY_SLAM,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLARE_BLITZ,
            [TYPE_WATER]    = MOVE_LIQUIDATION,
            [TYPE_GRASS]    = MOVE_WOOD_HAMMER,
            [TYPE_ELECTRIC] = MOVE_WILD_CHARGE,
            [TYPE_PSYCHIC]  = MOVE_ZEN_HEADBUTT,
            [TYPE_ICE]      = MOVE_ICICLE_CRASH,
            [TYPE_DRAGON]   = MOVE_DRAGON_RUSH,
            [TYPE_DARK]     = MOVE_FOUL_PLAY,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_HORN)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_HORN_ATTACK,
            [TYPE_FIGHTING] = MOVE_SACRED_SWORD,
            [TYPE_FLYING]   = MOVE_DRILL_PECK,
            [TYPE_POISON]   = MOVE_POISON_JAB,
            [TYPE_GROUND]   = MOVE_BONE_RUSH,
            [TYPE_ROCK]     = MOVE_STONE_EDGE,
            [TYPE_BUG]      = MOVE_MEGAHORN,
            [TYPE_GHOST]    = MOVE_PHANTOM_FORCE,
            [TYPE_STEEL]    = MOVE_SMART_STRIKE,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAME_CHARGE,
            [TYPE_WATER]    = MOVE_RAZOR_SHELL,
            [TYPE_GRASS]    = MOVE_HORN_LEECH,
            [TYPE_ELECTRIC] = MOVE_WILD_CHARGE,
            [TYPE_PSYCHIC]  = MOVE_PSYCHO_CUT,
            [TYPE_ICE]      = MOVE_ICICLE_SPEAR,
            [TYPE_DRAGON]   = MOVE_DRAGON_HAMMER,
            [TYPE_DARK]     = MOVE_KNOCK_OFF,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_HEAL_SAP)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_MORNING_SUN,
            [TYPE_FIGHTING] = MOVE_DETECT,
            [TYPE_FLYING]   = MOVE_ROOST,
            [TYPE_POISON]   = MOVE_ACID_ARMOR,
            [TYPE_GROUND]   = MOVE_SPIKES,
            [TYPE_ROCK]     = MOVE_SPIKES,
            [TYPE_BUG]      = MOVE_HEAL_ORDER,
            [TYPE_GHOST]    = MOVE_CURSE,
            [TYPE_STEEL]    = MOVE_IRON_DEFENSE,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_SPIN,
            [TYPE_WATER]    = MOVE_AQUA_RING,
            [TYPE_GRASS]    = MOVE_LEECH_SEED,
            [TYPE_ELECTRIC] = MOVE_CHARGE,
            [TYPE_PSYCHIC]  = MOVE_AMNESIA,
            [TYPE_ICE]      = MOVE_MIST,
            [TYPE_DRAGON]   = MOVE_DRAGON_DANCE,
            [TYPE_DARK]     = MOVE_FLATTER,
            [TYPE_FAIRY]    = MOVE_SWEET_KISS
        }
    },

    [PH_MOVE(MOVE_PH_ELEMENT_WEAK)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_ECHOED_VOICE,
            [TYPE_FIGHTING] = MOVE_BULK_UP,
            [TYPE_FLYING]   = MOVE_GUST,
            [TYPE_POISON]   = MOVE_ACID,
            [TYPE_GROUND]   = MOVE_MUD_SLAP,
            [TYPE_ROCK]     = MOVE_ROLLOUT,
            [TYPE_BUG]      = MOVE_TWINEEDLE,
            [TYPE_GHOST]    = MOVE_ASTONISH,
            [TYPE_STEEL]    = MOVE_THUNDER_SHOCK,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_EMBER,
            [TYPE_WATER]    = MOVE_WATER_GUN,
            [TYPE_GRASS]    = MOVE_ABSORB,
            [TYPE_ELECTRIC] = MOVE_THUNDER_SHOCK,
            [TYPE_PSYCHIC]  = MOVE_CONFUSION,
            [TYPE_ICE]      = MOVE_POWDER_SNOW,
            [TYPE_DRAGON]   = MOVE_TWISTER,
            [TYPE_DARK]     = MOVE_PURSUIT,
            [TYPE_FAIRY]    = MOVE_FAIRY_WIND
        }
    },

    [PH_MOVE(MOVE_PH_ELEMENT_WEAK2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_ECHOED_VOICE,
            [TYPE_FIGHTING] = MOVE_BULK_UP,
            [TYPE_FLYING]   = MOVE_GUST,
            [TYPE_POISON]   = MOVE_SMOG,
            [TYPE_GROUND]   = MOVE_MUD_SLAP,
            [TYPE_ROCK]     = MOVE_ROLLOUT,
            [TYPE_BUG]      = MOVE_TWINEEDLE,
            [TYPE_GHOST]    = MOVE_ASTONISH,
            [TYPE_STEEL]    = MOVE_THUNDER_SHOCK,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_EMBER,
            [TYPE_WATER]    = MOVE_BUBBLE,
            [TYPE_GRASS]    = MOVE_ABSORB,
            [TYPE_ELECTRIC] = MOVE_THUNDER_SHOCK,
            [TYPE_PSYCHIC]  = MOVE_CONFUSION,
            [TYPE_ICE]      = MOVE_POWDER_SNOW,
            [TYPE_DRAGON]   = MOVE_TWISTER,
            [TYPE_DARK]     = MOVE_PURSUIT,
            [TYPE_FAIRY]    = MOVE_FAIRY_WIND
        }
    },

    [PH_MOVE(MOVE_PH_SPATK_ADJACENT1)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_HYPER_VOICE,
            [TYPE_FIGHTING] = MOVE_HYPER_VOICE,
            [TYPE_FLYING]   = MOVE_AIR_CUTTER,
            [TYPE_POISON]   = MOVE_SLUDGE_WAVE,
            [TYPE_GROUND]   = MOVE_BULLDOZE,
            [TYPE_ROCK]     = MOVE_ROCK_SLIDE,
            [TYPE_BUG]      = MOVE_STRUGGLE_BUG,
            [TYPE_GHOST]    = MOVE_DISARMING_VOICE, //MOVE_EXPANDING_FORCE,
            [TYPE_STEEL]    = MOVE_DISCHARGE,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAME_BURST,
            [TYPE_WATER]    = MOVE_SPARKLING_ARIA,
            [TYPE_GRASS]    = MOVE_RAZOR_LEAF,
            [TYPE_ELECTRIC] = MOVE_DISCHARGE,
            [TYPE_PSYCHIC]  = MOVE_DISARMING_VOICE, //MOVE_EXPANDING_FORCE,
            [TYPE_ICE]      = MOVE_ICY_WIND,
            [TYPE_DRAGON]   = MOVE_TWISTER,
            [TYPE_DARK]     = MOVE_SNARL,
            [TYPE_FAIRY]    = MOVE_DISARMING_VOICE
        }
    },

    [PH_MOVE(MOVE_PH_SPATK_ADJACENT2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_BOOMBURST,
            [TYPE_FIGHTING] = MOVE_BOOMBURST,
            [TYPE_FLYING]   = MOVE_AIR_CUTTER,
            [TYPE_POISON]   = MOVE_SLUDGE_WAVE,
            [TYPE_GROUND]   = MOVE_EARTHQUAKE,
            [TYPE_ROCK]     = MOVE_ROCK_SLIDE,
            [TYPE_BUG]      = MOVE_STRUGGLE_BUG,
            [TYPE_GHOST]    = MOVE_DISARMING_VOICE, //MOVE_EXPANDING_FORCE,
            [TYPE_STEEL]    = MOVE_DISCHARGE,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_HEAT_WAVE,
            [TYPE_WATER]    = MOVE_WATER_SPOUT,
            [TYPE_GRASS]    = MOVE_PETAL_BLIZZARD,
            [TYPE_ELECTRIC] = MOVE_DISCHARGE,
            [TYPE_PSYCHIC]  = MOVE_DISARMING_VOICE, //MOVE_EXPANDING_FORCE,
            [TYPE_ICE]      = MOVE_BLIZZARD,
            [TYPE_DRAGON]   = MOVE_CLANGING_SCALES,
            [TYPE_DARK]     = MOVE_SNARL,
            [TYPE_FAIRY]    = MOVE_DAZZLING_GLEAM
        }
    },

    [PH_MOVE(MOVE_PH_FEET_MULTIHIT_FIXED)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_DOUBLE_HIT,
            [TYPE_FIGHTING] = MOVE_DOUBLE_KICK,
            [TYPE_FLYING]   = MOVE_DUAL_WINGBEAT,
            [TYPE_POISON]   = MOVE_DOUBLE_HIT,
            [TYPE_GROUND]   = MOVE_ROCK_BLAST,
            [TYPE_ROCK]     = MOVE_ROCK_BLAST,
            [TYPE_BUG]      = MOVE_TWINEEDLE,
            [TYPE_GHOST]    = MOVE_DOUBLE_HIT,
            [TYPE_STEEL]    = MOVE_DOUBLE_HIT,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_DOUBLE_HIT,
            [TYPE_WATER]    = MOVE_DOUBLE_HIT,
            [TYPE_GRASS]    = MOVE_DOUBLE_HIT,
            [TYPE_ELECTRIC] = MOVE_DOUBLE_HIT,
            [TYPE_PSYCHIC]  = MOVE_DOUBLE_HIT,
            [TYPE_ICE]      = MOVE_ICICLE_SPEAR,
            [TYPE_DRAGON]   = MOVE_DUAL_CHOP,
            [TYPE_DARK]     = MOVE_DOUBLE_HIT,
            [TYPE_FAIRY]    = MOVE_DOUBLE_HIT
        }
    },

    [PH_MOVE(MOVE_PH_BEAM1)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_TRI_ATTACK,
            [TYPE_FIGHTING] = MOVE_AURA_SPHERE,
            [TYPE_FLYING]   = MOVE_AIR_SLASH,
            [TYPE_POISON]   = MOVE_SLUDGE_BOMB,
            [TYPE_GROUND]   = MOVE_MUD_SHOT,
            [TYPE_ROCK]     = MOVE_POWER_GEM,
            [TYPE_BUG]      = MOVE_SILVER_WIND,
            [TYPE_GHOST]    = MOVE_OMINOUS_WIND,
            [TYPE_STEEL]    = MOVE_MIRROR_SHOT,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAMETHROWER,
            [TYPE_WATER]    = MOVE_WATER_PULSE,
            [TYPE_GRASS]    = MOVE_MEGA_DRAIN,
            [TYPE_ELECTRIC] = MOVE_THUNDERBOLT,
            [TYPE_PSYCHIC]  = MOVE_PSYBEAM,
            [TYPE_ICE]      = MOVE_AURORA_BEAM,
            [TYPE_DRAGON]   = MOVE_DRAGON_BREATH,
            [TYPE_DARK]     = MOVE_DARK_PULSE,
            [TYPE_FAIRY]    = MOVE_MOONBLAST
        }
    },

    [PH_MOVE(MOVE_PH_BEAM2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_TRI_ATTACK,
            [TYPE_FIGHTING] = MOVE_AURA_SPHERE,
            [TYPE_FLYING]   = MOVE_AIR_SLASH,
            [TYPE_POISON]   = MOVE_SLUDGE_BOMB,
            [TYPE_GROUND]   = MOVE_MUD_BOMB,
            [TYPE_ROCK]     = MOVE_POWER_GEM,
            [TYPE_BUG]      = MOVE_SIGNAL_BEAM,
            [TYPE_GHOST]    = MOVE_SHADOW_BALL,
            [TYPE_STEEL]    = MOVE_FLASH_CANNON,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAMETHROWER,
            [TYPE_WATER]    = MOVE_BUBBLE_BEAM,
            [TYPE_GRASS]    = MOVE_GIGA_DRAIN,
            [TYPE_ELECTRIC] = MOVE_THUNDERBOLT,
            [TYPE_PSYCHIC]  = MOVE_PSYCHIC,
            [TYPE_ICE]      = MOVE_ICE_BEAM,
            [TYPE_DRAGON]   = MOVE_DRAGON_PULSE,
            [TYPE_DARK]     = MOVE_DARK_PULSE,
            [TYPE_FAIRY]    = MOVE_MOONBLAST
        }
    },

    [PH_MOVE(MOVE_PH_BEAM3)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_HYPER_BEAM,
            [TYPE_FIGHTING] = MOVE_FOCUS_BLAST,
            [TYPE_FLYING]   = MOVE_HURRICANE,
            [TYPE_POISON]   = MOVE_SLUDGE_BOMB,
            [TYPE_GROUND]   = MOVE_METEOR_BEAM,
            [TYPE_ROCK]     = MOVE_METEOR_BEAM,
            [TYPE_BUG]      = MOVE_BUG_BUZZ,
            [TYPE_GHOST]    = MOVE_SHADOW_BALL,
            [TYPE_STEEL]    = MOVE_STEEL_BEAM,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_BLAST,
            [TYPE_WATER]    = MOVE_HYDRO_PUMP,
            [TYPE_GRASS]    = MOVE_LEAF_STORM,
            [TYPE_ELECTRIC] = MOVE_THUNDER,
            [TYPE_PSYCHIC]  = MOVE_FUTURE_SIGHT,
            [TYPE_ICE]      = MOVE_BLIZZARD,
            [TYPE_DRAGON]   = MOVE_DRACO_METEOR,
            [TYPE_DARK]     = MOVE_DARK_PULSE,
            [TYPE_FAIRY]    = MOVE_MOONBLAST
        }
    },

    [PH_MOVE(MOVE_PH_BEAM4)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_HYPER_BEAM,
            [TYPE_FIGHTING] = MOVE_FOCUS_BLAST,
            [TYPE_FLYING]   = MOVE_HURRICANE,
            [TYPE_POISON]   = MOVE_SLUDGE_BOMB,
            [TYPE_GROUND]   = MOVE_METEOR_BEAM,
            [TYPE_ROCK]     = MOVE_METEOR_BEAM,
            [TYPE_BUG]      = MOVE_POLLEN_PUFF,
            [TYPE_GHOST]    = MOVE_SHADOW_BALL,
            [TYPE_STEEL]    = MOVE_STEEL_BEAM,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_BLAST,
            [TYPE_WATER]    = MOVE_HYDRO_PUMP,
            [TYPE_GRASS]    = MOVE_SOLAR_BEAM,
            [TYPE_ELECTRIC] = MOVE_THUNDER,
            [TYPE_PSYCHIC]  = MOVE_FUTURE_SIGHT,
            [TYPE_ICE]      = MOVE_BLIZZARD,
            [TYPE_DRAGON]   = MOVE_DRACO_METEOR,
            [TYPE_DARK]     = MOVE_DARK_PULSE,
            [TYPE_FAIRY]    = MOVE_MOONBLAST
        }
    },

    [PH_MOVE(MOVE_PH_BALL)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_RAZOR_WIND,
            [TYPE_FIGHTING] = MOVE_AURA_SPHERE,
            [TYPE_FLYING]   = MOVE_AIR_CUTTER,
            [TYPE_POISON]   = MOVE_SLUDGE_BOMB,
            [TYPE_GROUND]   = MOVE_MUD_BOMB,
            [TYPE_ROCK]     = MOVE_MUD_BOMB,
            [TYPE_BUG]      = MOVE_SIGNAL_BEAM,
            [TYPE_GHOST]    = MOVE_SHADOW_BALL,
            [TYPE_STEEL]    = MOVE_STEEL_BEAM,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_MYSTICAL_FIRE,
            [TYPE_WATER]    = MOVE_WATER_PULSE,
            [TYPE_GRASS]    = MOVE_ENERGY_BALL,
            [TYPE_ELECTRIC] = MOVE_ELECTRO_BALL,
            [TYPE_PSYCHIC]  = MOVE_EXTRASENSORY,
            [TYPE_ICE]      = MOVE_FROST_BREATH,
            [TYPE_DRAGON]   = MOVE_DRAGON_PULSE,
            [TYPE_DARK]     = MOVE_DARK_PULSE,
            [TYPE_FAIRY]    = MOVE_MOONBLAST
        }
    },

    [PH_MOVE(MOVE_PH_BODY_ATK_SPEED)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_EXTREME_SPEED,
            [TYPE_FIGHTING] = MOVE_EXTREME_SPEED,
            [TYPE_FLYING]   = MOVE_EXTREME_SPEED,
            [TYPE_POISON]   = MOVE_EXTREME_SPEED,
            [TYPE_GROUND]   = MOVE_BULLDOZE,
            [TYPE_ROCK]     = MOVE_ACCELEROCK,
            [TYPE_BUG]      = MOVE_EXTREME_SPEED,
            [TYPE_GHOST]    = MOVE_SHADOW_SNEAK,
            [TYPE_STEEL]    = MOVE_EXTREME_SPEED,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAME_CHARGE,
            [TYPE_WATER]    = MOVE_AQUA_JET,
            [TYPE_GRASS]    = MOVE_GRASSY_GLIDE,
            [TYPE_ELECTRIC] = MOVE_WILD_CHARGE,
            [TYPE_PSYCHIC]  = MOVE_ZEN_HEADBUTT,
            [TYPE_ICE]      = MOVE_ICE_SHARD,
            [TYPE_DRAGON]   = MOVE_DRAGON_RUSH,
            [TYPE_DARK]     = MOVE_NIGHT_SLASH,
            [TYPE_FAIRY]    = MOVE_EXTREME_SPEED
        }
    },

    [PH_MOVE(MOVE_PH_BLADE)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_SLASH,
            [TYPE_FIGHTING] = MOVE_KARATE_CHOP,
            [TYPE_FLYING]   = MOVE_AERIAL_ACE,
            [TYPE_POISON]   = MOVE_CROSS_POISON,
            [TYPE_GROUND]   = MOVE_BONE_CLUB,
            [TYPE_ROCK]     = MOVE_BONE_CLUB,
            [TYPE_BUG]      = MOVE_X_SCISSOR,
            [TYPE_GHOST]    = MOVE_SHADOW_CLAW,
            [TYPE_STEEL]    = MOVE_STEEL_WING,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_LASH,
            [TYPE_WATER]    = MOVE_RAZOR_SHELL,
            [TYPE_GRASS]    = MOVE_LEAF_BLADE,
            [TYPE_ELECTRIC] = MOVE_SPARK,
            [TYPE_PSYCHIC]  = MOVE_PSYCHO_CUT,
            [TYPE_ICE]      = MOVE_ICICLE_SPEAR,
            [TYPE_DRAGON]   = MOVE_DRAGON_CLAW,
            [TYPE_DARK]     = MOVE_NIGHT_SLASH,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_FIST)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_MEGA_PUNCH,
            [TYPE_FIGHTING] = MOVE_POWER_UP_PUNCH,
            [TYPE_FLYING]   = MOVE_MEGA_PUNCH,
            [TYPE_POISON]   = MOVE_POISON_JAB,
            [TYPE_GROUND]   = MOVE_MEGA_PUNCH,
            [TYPE_ROCK]     = MOVE_SMACK_DOWN,
            [TYPE_BUG]      = MOVE_SKITTER_SMACK,
            [TYPE_GHOST]    = MOVE_SHADOW_PUNCH,
            [TYPE_STEEL]    = MOVE_BULLET_PUNCH,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_PUNCH,
            [TYPE_WATER]    = MOVE_CRABHAMMER,
            [TYPE_GRASS]    = MOVE_NEEDLE_ARM,
            [TYPE_ELECTRIC] = MOVE_THUNDER_PUNCH,
            [TYPE_PSYCHIC]  = MOVE_HEART_STAMP,
            [TYPE_ICE]      = MOVE_ICE_PUNCH,
            [TYPE_DRAGON]   = MOVE_DUAL_CHOP,
            [TYPE_DARK]     = MOVE_SUCKER_PUNCH,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_KICK)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_MEGA_KICK,
            [TYPE_FIGHTING] = MOVE_JUMP_KICK,
            [TYPE_FLYING]   = MOVE_BRAVE_BIRD,
            [TYPE_POISON]   = MOVE_POISON_JAB,
            [TYPE_GROUND]   = MOVE_HIGH_HORSEPOWER,
            [TYPE_ROCK]     = MOVE_HIGH_HORSEPOWER,
            [TYPE_BUG]      = MOVE_LUNGE,
            [TYPE_GHOST]    = MOVE_PHANTOM_FORCE,
            [TYPE_STEEL]    = MOVE_MEGA_KICK,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_BLAZE_KICK,
            [TYPE_WATER]    = MOVE_CRABHAMMER,
            [TYPE_GRASS]    = MOVE_TROP_KICK,
            [TYPE_ELECTRIC] = MOVE_WILD_CHARGE,
            [TYPE_PSYCHIC]  = MOVE_HEART_STAMP,
            [TYPE_ICE]      = MOVE_ICICLE_CRASH,
            [TYPE_DRAGON]   = MOVE_DRAGON_HAMMER,
            [TYPE_DARK]     = MOVE_THROAT_CHOP,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_BODY_RECOIL)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_TAKE_DOWN,
            [TYPE_FIGHTING] = MOVE_CLOSE_COMBAT,
            [TYPE_FLYING]   = MOVE_BRAVE_BIRD,
            [TYPE_POISON]   = MOVE_TAKE_DOWN,
            [TYPE_GROUND]   = MOVE_HEAD_SMASH,
            [TYPE_ROCK]     = MOVE_HEAD_SMASH,
            [TYPE_BUG]      = MOVE_TAKE_DOWN,
            [TYPE_GHOST]    = MOVE_TAKE_DOWN,
            [TYPE_STEEL]    = MOVE_TAKE_DOWN,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLARE_BLITZ,
            [TYPE_WATER]    = MOVE_LIQUIDATION,
            [TYPE_GRASS]    = MOVE_WOOD_HAMMER,
            [TYPE_ELECTRIC] = MOVE_WILD_CHARGE,
            [TYPE_PSYCHIC]  = MOVE_TAKE_DOWN,
            [TYPE_ICE]      = MOVE_ICE_BALL,
            [TYPE_DRAGON]   = MOVE_SCALE_SHOT,
            [TYPE_DARK]     = MOVE_TAKE_DOWN,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_HAZARD)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_PERISH_SONG,
            [TYPE_FIGHTING] = MOVE_SPIKES,
            [TYPE_FLYING]   = MOVE_DEFOG,
            [TYPE_POISON]   = MOVE_TOXIC_SPIKES,
            [TYPE_GROUND]   = MOVE_SPIKES,
            [TYPE_ROCK]     = MOVE_STEALTH_ROCK,
            [TYPE_BUG]      = MOVE_STICKY_WEB,
            [TYPE_GHOST]    = MOVE_DESTINY_BOND,
            [TYPE_STEEL]    = MOVE_SPIKES,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_SPIN,
            [TYPE_WATER]    = MOVE_WHIRLPOOL,
            [TYPE_GRASS]    = MOVE_GRASSY_TERRAIN,
            [TYPE_ELECTRIC] = MOVE_ELECTRIC_TERRAIN,
            [TYPE_PSYCHIC]  = MOVE_PSYCHIC_TERRAIN,
            [TYPE_ICE]      = MOVE_MIST,
            [TYPE_DRAGON]   = MOVE_SPIKES,
            [TYPE_DARK]     = MOVE_TORMENT,
            [TYPE_FAIRY]    = MOVE_MISTY_TERRAIN
        }
    },

    [PH_MOVE(MOVE_PH_WEATHER)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_WEATHER_BALL,
            [TYPE_FIGHTING] = MOVE_SPIKES,
            [TYPE_FLYING]   = MOVE_TAILWIND,
            [TYPE_POISON]   = MOVE_TOXIC_SPIKES,
            [TYPE_GROUND]   = MOVE_SANDSTORM,
            [TYPE_ROCK]     = MOVE_SANDSTORM,
            [TYPE_BUG]      = MOVE_STICKY_WEB,
            [TYPE_GHOST]    = MOVE_DESTINY_BOND,
            [TYPE_STEEL]    = MOVE_SANDSTORM,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_SUNNY_DAY,
            [TYPE_WATER]    = MOVE_RAIN_DANCE,
            [TYPE_GRASS]    = MOVE_SUNNY_DAY,
            [TYPE_ELECTRIC] = MOVE_RAIN_DANCE,
            [TYPE_PSYCHIC]  = MOVE_GRAVITY,
            [TYPE_ICE]      = MOVE_HAIL,
            [TYPE_DRAGON]   = MOVE_WEATHER_BALL,
            [TYPE_DARK]     = MOVE_TORMENT,
            [TYPE_FAIRY]    = MOVE_MISTY_TERRAIN
        }
    },

    [PH_MOVE(MOVE_PH_TYPE_EFF)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_ODOR_SLEUTH,
            [TYPE_FIGHTING] = MOVE_ODOR_SLEUTH,
            [TYPE_FLYING]   = MOVE_MIRROR_MOVE,
            [TYPE_POISON]   = MOVE_GASTRO_ACID,
            [TYPE_GROUND]   = MOVE_MUD_SPORT,
            [TYPE_ROCK]     = MOVE_TAR_SHOT,
            [TYPE_BUG]      = MOVE_POWDER,
            [TYPE_GHOST]    = MOVE_GRAVITY,
            [TYPE_STEEL]    = MOVE_IRON_DEFENSE,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_SUNNY_DAY,
            [TYPE_WATER]    = MOVE_WATER_SPORT,
            [TYPE_GRASS]    = MOVE_WORRY_SEED,
            [TYPE_ELECTRIC] = MOVE_ION_DELUGE,
            [TYPE_PSYCHIC]  = MOVE_MIRACLE_EYE,
            [TYPE_ICE]      = MOVE_HAIL,
            [TYPE_DRAGON]   = MOVE_SAFEGUARD,
            [TYPE_DARK]     = MOVE_SAFEGUARD,
            [TYPE_FAIRY]    = MOVE_GRAVITY
        }
    },

    [PH_MOVE(MOVE_PH_SPATK_ADJACENT1_MUD)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_HYPER_VOICE,
            [TYPE_FIGHTING] = MOVE_HYPER_VOICE,
            [TYPE_FLYING]   = MOVE_AIR_CUTTER,
            [TYPE_POISON]   = MOVE_SLUDGE_WAVE,
            [TYPE_GROUND]   = MOVE_BULLDOZE,
            [TYPE_ROCK]     = MOVE_ROCK_SLIDE,
            [TYPE_BUG]      = MOVE_STRUGGLE_BUG,
            [TYPE_GHOST]    = MOVE_DISARMING_VOICE, //MOVE_EXPANDING_FORCE,
            [TYPE_STEEL]    = MOVE_DISCHARGE,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAME_BURST,
            [TYPE_WATER]    = MOVE_MUDDY_WATER,
            [TYPE_GRASS]    = MOVE_RAZOR_LEAF,
            [TYPE_ELECTRIC] = MOVE_DISCHARGE,
            [TYPE_PSYCHIC]  = MOVE_DISARMING_VOICE, //MOVE_EXPANDING_FORCE,
            [TYPE_ICE]      = MOVE_ICY_WIND,
            [TYPE_DRAGON]   = MOVE_TWISTER,
            [TYPE_DARK]     = MOVE_SNARL,
            [TYPE_FAIRY]    = MOVE_DISARMING_VOICE
        }
    },

    [PH_MOVE(MOVE_PH_RECOVER)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_RECOVER,
            [TYPE_FIGHTING] = MOVE_RECOVER,
            [TYPE_FLYING]   = MOVE_ROOST,
            [TYPE_POISON]   = MOVE_RECOVER,
            [TYPE_GROUND]   = MOVE_RECOVER,
            [TYPE_ROCK]     = MOVE_RECOVER,
            [TYPE_BUG]      = MOVE_HEAL_ORDER,
            [TYPE_GHOST]    = MOVE_CURSE,
            [TYPE_STEEL]    = MOVE_RECOVER,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_MORNING_SUN,
            [TYPE_WATER]    = MOVE_AQUA_RING,
            [TYPE_GRASS]    = MOVE_SYNTHESIS,
            [TYPE_ELECTRIC] = MOVE_RECOVER,
            [TYPE_PSYCHIC]  = MOVE_MORNING_SUN,
            [TYPE_ICE]      = MOVE_RECOVER,
            [TYPE_DRAGON]   = MOVE_RECOVER,
            [TYPE_DARK]     = MOVE_MOONLIGHT,
            [TYPE_FAIRY]    = MOVE_MOONLIGHT
        }
    },

    [PH_MOVE(MOVE_PH_RECOVER2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_RECOVER,
            [TYPE_FIGHTING] = MOVE_RECOVER,
            [TYPE_FLYING]   = MOVE_ROOST,
            [TYPE_POISON]   = MOVE_RECOVER,
            [TYPE_GROUND]   = MOVE_RECOVER,
            [TYPE_ROCK]     = MOVE_RECOVER,
            [TYPE_BUG]      = MOVE_HEAL_ORDER,
            [TYPE_GHOST]    = MOVE_CURSE,
            [TYPE_STEEL]    = MOVE_RECOVER,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_MORNING_SUN,
            [TYPE_WATER]    = MOVE_AQUA_RING,
            [TYPE_GRASS]    = MOVE_INGRAIN,
            [TYPE_ELECTRIC] = MOVE_RECOVER,
            [TYPE_PSYCHIC]  = MOVE_MORNING_SUN,
            [TYPE_ICE]      = MOVE_RECOVER,
            [TYPE_DRAGON]   = MOVE_RECOVER,
            [TYPE_DARK]     = MOVE_MOONLIGHT,
            [TYPE_FAIRY]    = MOVE_MOONLIGHT
        }
    },

    [PH_MOVE(MOVE_PH_STRONGWIND)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_RAZOR_WIND,
            [TYPE_FIGHTING] = MOVE_RAZOR_WIND,
            [TYPE_FLYING]   = MOVE_HURRICANE,
            [TYPE_POISON]   = MOVE_RAZOR_WIND,
            [TYPE_GROUND]   = MOVE_RAZOR_WIND,
            [TYPE_ROCK]     = MOVE_RAZOR_WIND,
            [TYPE_BUG]      = MOVE_SILVER_WIND,
            [TYPE_GHOST]    = MOVE_OMINOUS_WIND,
            [TYPE_STEEL]    = MOVE_RAZOR_WIND,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_HEAT_WAVE,
            [TYPE_WATER]    = MOVE_SURF,
            [TYPE_GRASS]    = MOVE_LEAF_TORNADO,
            [TYPE_ELECTRIC] = MOVE_DISCHARGE,
            [TYPE_PSYCHIC]  = MOVE_RAZOR_WIND,
            [TYPE_ICE]      = MOVE_ICY_WIND,
            [TYPE_DRAGON]   = MOVE_RAZOR_WIND,
            [TYPE_DARK]     = MOVE_RAZOR_WIND,
            [TYPE_FAIRY]    = MOVE_RAZOR_WIND
        }
    },

    [PH_MOVE(MOVE_PH_THRASH)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_THRASH,
            [TYPE_FIGHTING] = MOVE_SUPERPOWER,
            [TYPE_FLYING]   = MOVE_SKY_ATTACK,
            [TYPE_POISON]   = MOVE_GUNK_SHOT,
            [TYPE_GROUND]   = MOVE_EARTHQUAKE,
            [TYPE_ROCK]     = MOVE_ROCK_WRECKER,
            [TYPE_BUG]      = MOVE_MEGAHORN,
            [TYPE_GHOST]    = MOVE_POLTERGEIST,
            [TYPE_STEEL]    = MOVE_STEEL_ROLLER,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_OVERHEAT,
            [TYPE_WATER]    = MOVE_WATER_SPOUT,
            [TYPE_GRASS]    = MOVE_PETAL_DANCE,
            [TYPE_ELECTRIC] = MOVE_VOLT_TACKLE,
            [TYPE_PSYCHIC]  = MOVE_FUTURE_SIGHT,
            [TYPE_ICE]      = MOVE_ICE_HAMMER,
            [TYPE_DRAGON]   = MOVE_OUTRAGE,
            [TYPE_DARK]     = MOVE_FOUL_PLAY,
            [TYPE_FAIRY]    = MOVE_MISTY_EXPLOSION
        }
    },

    [PH_MOVE(MOVE_PH_BODY_2TURN)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_SLAM,
            [TYPE_FIGHTING] = MOVE_SUBMISSION,
            [TYPE_FLYING]   = MOVE_FLY,
            [TYPE_POISON]   = MOVE_GUNK_SHOT,
            [TYPE_GROUND]   = MOVE_DIG,
            [TYPE_ROCK]     = MOVE_METEOR_BEAM,
            [TYPE_BUG]      = MOVE_LUNGE,
            [TYPE_GHOST]    = MOVE_PHANTOM_FORCE,
            [TYPE_STEEL]    = MOVE_HEAVY_SLAM,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLARE_BLITZ,
            [TYPE_WATER]    = MOVE_DIVE,
            [TYPE_GRASS]    = MOVE_SOLAR_BLADE,
            [TYPE_ELECTRIC] = MOVE_VOLT_TACKLE,
            [TYPE_PSYCHIC]  = MOVE_ZEN_HEADBUTT,
            [TYPE_ICE]      = MOVE_ICICLE_CRASH,
            [TYPE_DRAGON]   = MOVE_DRAGON_RUSH,
            [TYPE_DARK]     = MOVE_FOUL_PLAY,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_ATK_LOWERSPEED)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_CONSTRICT,
            [TYPE_FIGHTING] = MOVE_LOW_SWEEP,
            [TYPE_FLYING]   = MOVE_CONSTRICT,
            [TYPE_POISON]   = MOVE_CONSTRICT,
            [TYPE_GROUND]   = MOVE_BULLDOZE,
            [TYPE_ROCK]     = MOVE_ROCK_TOMB,
            [TYPE_BUG]      = MOVE_CONSTRICT,
            [TYPE_GHOST]    = MOVE_CONSTRICT,
            [TYPE_STEEL]    = MOVE_CONSTRICT,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAME_CHARGE,
            [TYPE_WATER]    = MOVE_BUBBLE_BEAM,
            [TYPE_GRASS]    = MOVE_CONSTRICT,
            [TYPE_ELECTRIC] = MOVE_ELECTROWEB,
            [TYPE_PSYCHIC]  = MOVE_CONSTRICT,
            [TYPE_ICE]      = MOVE_ICY_WIND,
            [TYPE_DRAGON]   = MOVE_CONSTRICT,
            [TYPE_DARK]     = MOVE_CONSTRICT,
            [TYPE_FAIRY]    = MOVE_CONSTRICT
        }
    },

    [PH_MOVE(MOVE_PH_WINGS)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_WING_ATTACK,
            [TYPE_FIGHTING] = MOVE_DUAL_WINGBEAT,
            [TYPE_FLYING]   = MOVE_WING_ATTACK,
            [TYPE_POISON]   = MOVE_WING_ATTACK,
            [TYPE_GROUND]   = MOVE_WING_ATTACK,
            [TYPE_ROCK]     = MOVE_STEEL_WING,
            [TYPE_BUG]      = MOVE_DUAL_WINGBEAT,
            [TYPE_GHOST]    = MOVE_WING_ATTACK,
            [TYPE_STEEL]    = MOVE_STEEL_WING,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_WING_ATTACK,
            [TYPE_WATER]    = MOVE_WING_ATTACK,
            [TYPE_GRASS]    = MOVE_WING_ATTACK,
            [TYPE_ELECTRIC] = MOVE_WING_ATTACK,
            [TYPE_PSYCHIC]  = MOVE_WING_ATTACK,
            [TYPE_ICE]      = MOVE_WING_ATTACK,
            [TYPE_DRAGON]   = MOVE_DUAL_WINGBEAT,
            [TYPE_DARK]     = MOVE_DUAL_WINGBEAT,
            [TYPE_FAIRY]    = MOVE_WING_ATTACK
        }
    },

    [PH_MOVE(MOVE_PH_ATK_TRAP)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_BIND,
            [TYPE_FIGHTING] = MOVE_WRAP,
            [TYPE_FLYING]   = MOVE_WRAP,
            [TYPE_POISON]   = MOVE_BIND,
            [TYPE_GROUND]   = MOVE_SAND_TOMB,
            [TYPE_ROCK]     = MOVE_BIND,
            [TYPE_BUG]      = MOVE_INFESTATION,
            [TYPE_GHOST]    = MOVE_BIND,
            [TYPE_STEEL]    = MOVE_BIND,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_SPIN,
            [TYPE_WATER]    = MOVE_CLAMP,
            [TYPE_GRASS]    = MOVE_SNAP_TRAP,
            [TYPE_ELECTRIC] = MOVE_WRAP,
            [TYPE_PSYCHIC]  = MOVE_BIND,
            [TYPE_ICE]      = MOVE_WRAP,
            [TYPE_DRAGON]   = MOVE_BIND,
            [TYPE_DARK]     = MOVE_BIND,
            [TYPE_FAIRY]    = MOVE_WRAP
        }
    },

    [PH_MOVE(MOVE_PH_STATUS)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_YAWN,
            [TYPE_FIGHTING] = MOVE_YAWN,
            [TYPE_FLYING]   = MOVE_GLARE,
            [TYPE_POISON]   = MOVE_POISON_GAS,
            [TYPE_GROUND]   = MOVE_SPIKES,
            [TYPE_ROCK]     = MOVE_STEALTH_ROCK,
            [TYPE_BUG]      = MOVE_TOXIC_THREAD,
            [TYPE_GHOST]    = MOVE_WILL_O_WISP,
            [TYPE_STEEL]    = MOVE_SPIKES,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_WILL_O_WISP,
            [TYPE_WATER]    = MOVE_YAWN,
            [TYPE_GRASS]    = MOVE_SLEEP_POWDER,
            [TYPE_ELECTRIC] = MOVE_THUNDER_WAVE,
            [TYPE_PSYCHIC]  = MOVE_HYPNOSIS,
            [TYPE_ICE]      = MOVE_HAIL,
            [TYPE_DRAGON]   = MOVE_GLARE,
            [TYPE_DARK]     = MOVE_GLARE,
            [TYPE_FAIRY]    = MOVE_SING
        }
    },

    [PH_MOVE(MOVE_PH_STATUS2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_YAWN,
            [TYPE_FIGHTING] = MOVE_YAWN,
            [TYPE_FLYING]   = MOVE_GLARE,
            [TYPE_POISON]   = MOVE_TOXIC,
            [TYPE_GROUND]   = MOVE_STEALTH_ROCK,
            [TYPE_ROCK]     = MOVE_SPIKES,
            [TYPE_BUG]      = MOVE_TOXIC_THREAD,
            [TYPE_GHOST]    = MOVE_HYPNOSIS,
            [TYPE_STEEL]    = MOVE_SPIKES,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_WILL_O_WISP,
            [TYPE_WATER]    = MOVE_YAWN,
            [TYPE_GRASS]    = MOVE_GRASS_WHISTLE,
            [TYPE_ELECTRIC] = MOVE_THUNDER_WAVE,
            [TYPE_PSYCHIC]  = MOVE_HYPNOSIS,
            [TYPE_ICE]      = MOVE_HAIL,
            [TYPE_DRAGON]   = MOVE_GLARE,
            [TYPE_DARK]     = MOVE_GLARE,
            [TYPE_FAIRY]    = MOVE_SING
        }
    },

    [PH_MOVE(MOVE_PH_STATUS3)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_YAWN,
            [TYPE_FIGHTING] = MOVE_YAWN,
            [TYPE_FLYING]   = MOVE_GLARE,
            [TYPE_POISON]   = MOVE_TOXIC,
            [TYPE_GROUND]   = MOVE_STEALTH_ROCK,
            [TYPE_ROCK]     = MOVE_SPIKES,
            [TYPE_BUG]      = MOVE_TOXIC_THREAD,
            [TYPE_GHOST]    = MOVE_HYPNOSIS,
            [TYPE_STEEL]    = MOVE_SPIKES,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_WILL_O_WISP,
            [TYPE_WATER]    = MOVE_YAWN,
            [TYPE_GRASS]    = MOVE_SPORE,
            [TYPE_ELECTRIC] = MOVE_THUNDER_WAVE,
            [TYPE_PSYCHIC]  = MOVE_HYPNOSIS,
            [TYPE_ICE]      = MOVE_HAIL,
            [TYPE_DRAGON]   = MOVE_GLARE,
            [TYPE_DARK]     = MOVE_GLARE,
            [TYPE_FAIRY]    = MOVE_SING
        }
    },

    [PH_MOVE(MOVE_PH_STATUS4)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_YAWN,
            [TYPE_FIGHTING] = MOVE_YAWN,
            [TYPE_FLYING]   = MOVE_GLARE,
            [TYPE_POISON]   = MOVE_POISON_POWDER,
            [TYPE_GROUND]   = MOVE_STEALTH_ROCK,
            [TYPE_ROCK]     = MOVE_SPIKES,
            [TYPE_BUG]      = MOVE_TOXIC_THREAD,
            [TYPE_GHOST]    = MOVE_HYPNOSIS,
            [TYPE_STEEL]    = MOVE_SPIKES,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_WILL_O_WISP,
            [TYPE_WATER]    = MOVE_YAWN,
            [TYPE_GRASS]    = MOVE_STUN_SPORE,
            [TYPE_ELECTRIC] = MOVE_THUNDER_WAVE,
            [TYPE_PSYCHIC]  = MOVE_HYPNOSIS,
            [TYPE_ICE]      = MOVE_HAIL,
            [TYPE_DRAGON]   = MOVE_GLARE,
            [TYPE_DARK]     = MOVE_GLARE,
            [TYPE_FAIRY]    = MOVE_SING
        }
    },

    [PH_MOVE(MOVE_PH_SWIFT)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_SWIFT,
            [TYPE_FIGHTING] = MOVE_AURA_SPHERE,
            [TYPE_FLYING]   = MOVE_AERIAL_ACE,
            [TYPE_POISON]   = MOVE_CLEAR_SMOG,
            [TYPE_GROUND]   = MOVE_SWIFT,
            [TYPE_ROCK]     = MOVE_SWIFT,
            [TYPE_BUG]      = MOVE_SWIFT,
            [TYPE_GHOST]    = MOVE_SHADOW_PUNCH,
            [TYPE_STEEL]    = MOVE_MAGNET_BOMB,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAMETHROWER,
            [TYPE_WATER]    = MOVE_BUBBLE_BEAM,
            [TYPE_GRASS]    = MOVE_MAGICAL_LEAF,
            [TYPE_ELECTRIC] = MOVE_SHOCK_WAVE,
            [TYPE_PSYCHIC]  = MOVE_SWIFT,
            [TYPE_ICE]      = MOVE_ICE_BEAM,
            [TYPE_DRAGON]   = MOVE_SWIFT,
            [TYPE_DARK]     = MOVE_FEINT_ATTACK,
            [TYPE_FAIRY]    = MOVE_DISARMING_VOICE
        }
    },

    [PH_MOVE(MOVE_PH_TAIL)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_TAIL_SLAP,
            [TYPE_FIGHTING] = MOVE_DOUBLE_HIT,
            [TYPE_FLYING]   = MOVE_TAIL_SLAP,
            [TYPE_POISON]   = MOVE_POISON_TAIL,
            [TYPE_GROUND]   = MOVE_SLAM,
            [TYPE_ROCK]     = MOVE_SLAM,
            [TYPE_BUG]      = MOVE_TAIL_SLAP,
            [TYPE_GHOST]    = MOVE_TAIL_SLAP,
            [TYPE_STEEL]    = MOVE_IRON_TAIL,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_SLAM,
            [TYPE_WATER]    = MOVE_AQUA_TAIL,
            [TYPE_GRASS]    = MOVE_SLAM,
            [TYPE_ELECTRIC] = MOVE_SLAM,
            [TYPE_PSYCHIC]  = MOVE_TAIL_SLAP,
            [TYPE_ICE]      = MOVE_SLAM,
            [TYPE_DRAGON]   = MOVE_DRAGON_TAIL,
            [TYPE_DARK]     = MOVE_SLAM,
            [TYPE_FAIRY]    = MOVE_TAIL_SLAP
        }
    },

    [PH_MOVE(MOVE_PH_LOWER_DEFSPDEF)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_SCREECH,
            [TYPE_FIGHTING] = MOVE_SCREECH,
            [TYPE_FLYING]   = MOVE_SCREECH,
            [TYPE_POISON]   = MOVE_ACID_SPRAY,
            [TYPE_GROUND]   = MOVE_SCREECH,
            [TYPE_ROCK]     = MOVE_SCREECH,
            [TYPE_BUG]      = MOVE_SCREECH,
            [TYPE_GHOST]    = MOVE_SCREECH,
            [TYPE_STEEL]    = MOVE_METAL_SOUND,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FAKE_TEARS,
            [TYPE_WATER]    = MOVE_FAKE_TEARS,
            [TYPE_GRASS]    = MOVE_FAKE_TEARS,
            [TYPE_ELECTRIC] = MOVE_FAKE_TEARS,
            [TYPE_PSYCHIC]  = MOVE_FAKE_TEARS,
            [TYPE_ICE]      = MOVE_SCREECH,
            [TYPE_DRAGON]   = MOVE_SCREECH,
            [TYPE_DARK]     = MOVE_FAKE_TEARS,
            [TYPE_FAIRY]    = MOVE_SCREECH
        }
    },

    [PH_MOVE(MOVE_PH_BITE2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_CRUNCH,
            [TYPE_FIGHTING] = MOVE_CRUNCH,
            [TYPE_FLYING]   = MOVE_CRUNCH,
            [TYPE_POISON]   = MOVE_POISON_FANG,
            [TYPE_GROUND]   = MOVE_CRUNCH,
            [TYPE_ROCK]     = MOVE_CRUNCH,
            [TYPE_BUG]      = MOVE_BUG_BITE,
            [TYPE_GHOST]    = MOVE_LICK,
            [TYPE_STEEL]    = MOVE_CRUNCH,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_FANG,
            [TYPE_WATER]    = MOVE_CLAMP,
            [TYPE_GRASS]    = MOVE_BULLET_SEED,
            [TYPE_ELECTRIC] = MOVE_THUNDER_FANG,
            [TYPE_PSYCHIC]  = MOVE_CRUNCH,
            [TYPE_ICE]      = MOVE_ICE_FANG,
            [TYPE_DRAGON]   = MOVE_CRUNCH,
            [TYPE_DARK]     = MOVE_CRUNCH,
            [TYPE_FAIRY]    = MOVE_CRUNCH
        }
    },

    [PH_MOVE(MOVE_PH_ATK_THROW)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_STRENGTH,
            [TYPE_FIGHTING] = MOVE_VITAL_THROW,
            [TYPE_FLYING]   = MOVE_SKY_DROP,
            [TYPE_POISON]   = MOVE_SLUDGE,
            [TYPE_GROUND]   = MOVE_BONE_CLUB,
            [TYPE_ROCK]     = MOVE_ROCK_THROW,
            [TYPE_BUG]      = MOVE_POLLEN_PUFF,
            [TYPE_GHOST]    = MOVE_SHADOW_SNEAK,
            [TYPE_STEEL]    = MOVE_MAGNET_BOMB,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_INCINERATE,
            [TYPE_WATER]    = MOVE_WATERFALL,
            [TYPE_GRASS]    = MOVE_SEED_BOMB,
            [TYPE_ELECTRIC] = MOVE_CHARGE_BEAM,
            [TYPE_PSYCHIC]  = MOVE_ZEN_HEADBUTT,
            [TYPE_ICE]      = MOVE_ICICLE_CRASH,
            [TYPE_DRAGON]   = MOVE_DRAGON_PULSE,
            [TYPE_DARK]     = MOVE_THIEF,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_VARDMG)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_SONIC_BOOM,
            [TYPE_FIGHTING] = MOVE_SEISMIC_TOSS,
            [TYPE_FLYING]   = MOVE_SEISMIC_TOSS,
            [TYPE_POISON]   = MOVE_VENOSHOCK,
            [TYPE_GROUND]   = MOVE_MAGNITUDE,
            [TYPE_ROCK]     = MOVE_ROCK_TOMB,
            [TYPE_BUG]      = MOVE_PSYWAVE,
            [TYPE_GHOST]    = MOVE_NIGHT_SHADE,
            [TYPE_STEEL]    = MOVE_METAL_BURST,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_HEAT_CRASH,
            [TYPE_WATER]    = MOVE_BRINE,
            [TYPE_GRASS]    = MOVE_GRASS_KNOT,
            [TYPE_ELECTRIC] = MOVE_ELECTRO_BALL,
            [TYPE_PSYCHIC]  = MOVE_PSYWAVE,
            [TYPE_ICE]      = MOVE_ICE_BALL,
            [TYPE_DRAGON]   = MOVE_DRAGON_RAGE,
            [TYPE_DARK]     = MOVE_NIGHT_SHADE,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_FIST2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_MEGA_PUNCH,
            [TYPE_FIGHTING] = MOVE_ARM_THRUST,
            [TYPE_FLYING]   = MOVE_MEGA_PUNCH,
            [TYPE_POISON]   = MOVE_POISON_JAB,
            [TYPE_GROUND]   = MOVE_MEGA_PUNCH,
            [TYPE_ROCK]     = MOVE_SMACK_DOWN,
            [TYPE_BUG]      = MOVE_SKITTER_SMACK,
            [TYPE_GHOST]    = MOVE_SHADOW_PUNCH,
            [TYPE_STEEL]    = MOVE_BULLET_PUNCH,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_PUNCH,
            [TYPE_WATER]    = MOVE_CRABHAMMER,
            [TYPE_GRASS]    = MOVE_NEEDLE_ARM,
            [TYPE_ELECTRIC] = MOVE_THUNDER_PUNCH,
            [TYPE_PSYCHIC]  = MOVE_HEART_STAMP,
            [TYPE_ICE]      = MOVE_ICE_PUNCH,
            [TYPE_DRAGON]   = MOVE_DUAL_CHOP,
            [TYPE_DARK]     = MOVE_SUCKER_PUNCH,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_FIST3)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_MEGA_PUNCH,
            [TYPE_FIGHTING] = MOVE_FORCE_PALM,
            [TYPE_FLYING]   = MOVE_MEGA_PUNCH,
            [TYPE_POISON]   = MOVE_POISON_JAB,
            [TYPE_GROUND]   = MOVE_MEGA_PUNCH,
            [TYPE_ROCK]     = MOVE_SMACK_DOWN,
            [TYPE_BUG]      = MOVE_SKITTER_SMACK,
            [TYPE_GHOST]    = MOVE_SHADOW_PUNCH,
            [TYPE_STEEL]    = MOVE_BULLET_PUNCH,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_PUNCH,
            [TYPE_WATER]    = MOVE_CRABHAMMER,
            [TYPE_GRASS]    = MOVE_NEEDLE_ARM,
            [TYPE_ELECTRIC] = MOVE_THUNDER_PUNCH,
            [TYPE_PSYCHIC]  = MOVE_HEART_STAMP,
            [TYPE_ICE]      = MOVE_ICE_PUNCH,
            [TYPE_DRAGON]   = MOVE_DUAL_CHOP,
            [TYPE_DARK]     = MOVE_SUCKER_PUNCH,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_PRIORITY)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_QUICK_ATTACK,
            [TYPE_FIGHTING] = MOVE_MACH_PUNCH,
            [TYPE_FLYING]   = MOVE_QUICK_ATTACK,
            [TYPE_POISON]   = MOVE_POISON_JAB,
            [TYPE_GROUND]   = MOVE_BULLDOZE,
            [TYPE_ROCK]     = MOVE_ACCELEROCK,
            [TYPE_BUG]      = MOVE_SKITTER_SMACK,
            [TYPE_GHOST]    = MOVE_SHADOW_SNEAK,
            [TYPE_STEEL]    = MOVE_BULLET_PUNCH,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAME_CHARGE,
            [TYPE_WATER]    = MOVE_AQUA_JET,
            [TYPE_GRASS]    = MOVE_NEEDLE_ARM,
            [TYPE_ELECTRIC] = MOVE_THUNDER_PUNCH,
            [TYPE_PSYCHIC]  = MOVE_HEART_STAMP,
            [TYPE_ICE]      = MOVE_ICE_SHARD,
            [TYPE_DRAGON]   = MOVE_DUAL_CHOP,
            [TYPE_DARK]     = MOVE_SUCKER_PUNCH,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    },

    [PH_MOVE(MOVE_PH_ELEMENT_STRONG)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_HYPER_VOICE,
            [TYPE_FIGHTING] = MOVE_AURA_SPHERE,
            [TYPE_FLYING]   = MOVE_AIR_SLASH,
            [TYPE_POISON]   = MOVE_SLUDGE_BOMB,
            [TYPE_GROUND]   = MOVE_EARTH_POWER,
            [TYPE_ROCK]     = MOVE_POWER_GEM,
            [TYPE_BUG]      = MOVE_BUG_BUZZ,
            [TYPE_GHOST]    = MOVE_SHADOW_BALL,
            [TYPE_STEEL]    = MOVE_FLASH_CANNON,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FLAMETHROWER,
            [TYPE_WATER]    = MOVE_SURF,
            [TYPE_GRASS]    = MOVE_ENERGY_BALL,
            [TYPE_ELECTRIC] = MOVE_THUNDERBOLT,
            [TYPE_PSYCHIC]  = MOVE_PSYCHIC,
            [TYPE_ICE]      = MOVE_ICE_BEAM,
            [TYPE_DRAGON]   = MOVE_DRAGON_PULSE,
            [TYPE_DARK]     = MOVE_DARK_PULSE,
            [TYPE_FAIRY]    = MOVE_MOONBLAST
        }
    },

    [PH_MOVE(MOVE_PH_ELEMENT_STRONG2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_TRI_ATTACK,
            [TYPE_FIGHTING] = MOVE_AURA_SPHERE,
            [TYPE_FLYING]   = MOVE_AIR_SLASH,
            [TYPE_POISON]   = MOVE_SLUDGE_BOMB,
            [TYPE_GROUND]   = MOVE_EARTH_POWER,
            [TYPE_ROCK]     = MOVE_POWER_GEM,
            [TYPE_BUG]      = MOVE_LEECH_LIFE,
            [TYPE_GHOST]    = MOVE_SHADOW_BALL,
            [TYPE_STEEL]    = MOVE_FLASH_CANNON,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_LAVA_PLUME,
            [TYPE_WATER]    = MOVE_SCALD,
            [TYPE_GRASS]    = MOVE_ENERGY_BALL,
            [TYPE_ELECTRIC] = MOVE_DISCHARGE,
            [TYPE_PSYCHIC]  = MOVE_PSYCHIC,
            [TYPE_ICE]      = MOVE_ICE_BEAM,
            [TYPE_DRAGON]   = MOVE_DRAGON_PULSE,
            [TYPE_DARK]     = MOVE_NIGHT_DAZE,
            [TYPE_FAIRY]    = MOVE_DAZZLING_GLEAM
        }
    },

    [PH_MOVE(MOVE_PH_BLADE2)] =
    {
        .move =
        {
            [TYPE_NORMAL]   = MOVE_CHIP_AWAY,
            [TYPE_FIGHTING] = MOVE_KARATE_CHOP,
            [TYPE_FLYING]   = MOVE_AERIAL_ACE,
            [TYPE_POISON]   = MOVE_CROSS_POISON,
            [TYPE_GROUND]   = MOVE_BONE_CLUB,
            [TYPE_ROCK]     = MOVE_BONE_CLUB,
            [TYPE_BUG]      = MOVE_FURY_CUTTER,
            [TYPE_GHOST]    = MOVE_SHADOW_CLAW,
            [TYPE_STEEL]    = MOVE_STEEL_WING,
            [TYPE_MYSTERY]  = MOVE_SKETCH,
            [TYPE_FIRE]     = MOVE_FIRE_LASH,
            [TYPE_WATER]    = MOVE_RAZOR_SHELL,
            [TYPE_GRASS]    = MOVE_LEAF_BLADE,
            [TYPE_ELECTRIC] = MOVE_SPARK,
            [TYPE_PSYCHIC]  = MOVE_PSYCHO_CUT,
            [TYPE_ICE]      = MOVE_ICICLE_SPEAR,
            [TYPE_DRAGON]   = MOVE_DRAGON_CLAW,
            [TYPE_DARK]     = MOVE_NIGHT_SLASH,
            [TYPE_FAIRY]    = MOVE_PLAY_ROUGH
        }
    }
};
