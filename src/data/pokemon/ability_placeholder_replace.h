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
    }
};
