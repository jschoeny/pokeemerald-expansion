#define PH_ABILITY(ability) ability - (ABILITIES_PH_START + 1)

const struct PlaceholderAbility gPlaceholderAbilities[ABILITIES_PH_COUNT] =
{
    [PH_ABILITY(ABILITY_PH_STARTER)] =
    {
        .ability =
        {
            ABILITY_GUTS,       // Normal
            ABILITY_GUTS,       // Fighting
            ABILITY_KEEN_EYE,   // Flying
            ABILITY_STENCH,     // Poison
            ABILITY_SAND_VEIL,  // Ground
            ABILITY_SAND_VEIL,  // Rock
            ABILITY_SWARM,      // Bug
            ABILITY_INFILTRATOR,// Ghost
            ABILITY_STURDY,     // Steel
            ABILITY_NONE,       // Mystery
            ABILITY_BLAZE,      // Fire
            ABILITY_TORRENT,    // Water
            ABILITY_OVERGROW,   // Grass
            ABILITY_STATIC,     // Electric
            ABILITY_SYNCHRONIZE,// Psychic
            ABILITY_SNOW_CLOAK, // Ice
            ABILITY_MARVEL_SCALE,// Dragon
            ABILITY_SYNCHRONIZE,// Dark
            ABILITY_PRANKSTER   // Fairy
        }
    },

    [PH_ABILITY(ABILITY_PH_WEATHER_STATS)] =
    {
        .ability =
        {
            ABILITY_GUTS,       // Normal
            ABILITY_GUTS,       // Fighting
            ABILITY_GUTS,       // Flying
            ABILITY_GUTS,       // Poison
            ABILITY_SAND_RUSH,  // Ground
            ABILITY_SAND_RUSH,  // Rock
            ABILITY_GUTS,       // Bug
            ABILITY_GUTS,       // Ghost
            ABILITY_GUTS,       // Steel
            ABILITY_NONE,       // Mystery
            ABILITY_SOLAR_POWER,// Fire
            ABILITY_SWIFT_SWIM, // Water
            ABILITY_CHLOROPHYLL,// Grass
            ABILITY_GUTS,       // Electric
            ABILITY_GUTS,       // Psychic
            ABILITY_SLUSH_RUSH, // Ice
            ABILITY_GUTS,       // Dragon
            ABILITY_GUTS,       // Dark
            ABILITY_GUTS        // Fairy
        }
    },

    [PH_ABILITY(ABILITY_PH_STATUS)] =
    {
        .ability =
        {
            ABILITY_ROUGH_SKIN, // Normal
            ABILITY_ROUGH_SKIN, // Fighting
            ABILITY_KEEN_EYE,   // Flying
            ABILITY_POISON_POINT,// Poison
            ABILITY_SAND_VEIL,  // Ground
            ABILITY_SAND_VEIL,  // Rock
            ABILITY_COMPOUND_EYES,// Bug
            ABILITY_CURSED_BODY,// Ghost
            ABILITY_IRON_BARBS, // Steel
            ABILITY_NONE,       // Mystery
            ABILITY_FLAME_BODY, // Fire
            ABILITY_DAMP,       // Water
            ABILITY_EFFECT_SPORE,// Grass
            ABILITY_STATIC,     // Electric
            ABILITY_SYNCHRONIZE,// Psychic
            ABILITY_ICE_BODY,   // Ice
            ABILITY_INTIMIDATE, // Dragon
            ABILITY_INTIMIDATE, // Dark
            ABILITY_CUTE_CHARM  // Fairy
        }
    },

    [PH_ABILITY(ABILITY_PH_PREVENT)] =
    {
        .ability =
        {
            ABILITY_LIMBER,     // Normal
            ABILITY_INNER_FOCUS,// Fighting
            ABILITY_KEEN_EYE,   // Flying
            ABILITY_STICKY_HOLD,// Poison
            ABILITY_LIGHTNING_ROD,// Ground
            ABILITY_SOLID_ROCK, // Rock
            ABILITY_SHIELD_DUST,// Bug
            ABILITY_IMMUNITY,   // Ghost
            ABILITY_BULLETPROOF,// Steel
            ABILITY_NONE,       // Mystery
            ABILITY_MAGMA_ARMOR,// Fire
            ABILITY_DAMP,       // Water
            ABILITY_LEAF_GUARD, // Grass
            ABILITY_LIGHTNING_ROD,// Electric
            ABILITY_TELEPATHY,  // Psychic
            ABILITY_CLEAR_BODY, // Ice
            ABILITY_MULTISCALE, // Dragon
            ABILITY_INNER_FOCUS,// Dark
            ABILITY_AROMA_VEIL  // Fairy
        }
    },

    [PH_ABILITY(ABILITY_PH_PREVENT2)] =
    {
        .ability =
        {
            ABILITY_LIMBER,     // Normal
            ABILITY_VITAL_SPIRIT,// Fighting
            ABILITY_KEEN_EYE,   // Flying
            ABILITY_STICKY_HOLD,// Poison
            ABILITY_SAND_VEIL,  // Ground
            ABILITY_STURDY,     // Rock
            ABILITY_WONDER_SKIN,// Bug
            ABILITY_CLEAR_BODY, // Ghost
            ABILITY_HEAVY_METAL,// Steel
            ABILITY_NONE,       // Mystery
            ABILITY_FLASH_FIRE, // Fire
            ABILITY_WATER_ABSORB,// Water
            ABILITY_SAP_SIPPER, // Grass
            ABILITY_VOLT_ABSORB,// Electric
            ABILITY_MAGIC_BOUNCE,// Psychic
            ABILITY_DRY_SKIN,   // Ice
            ABILITY_MARVEL_SCALE,// Dragon
            ABILITY_TELEPATHY,  // Dark
            ABILITY_DAZZLING    // Fairy
        }
    }
};
