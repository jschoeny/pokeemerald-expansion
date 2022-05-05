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
    }
};
