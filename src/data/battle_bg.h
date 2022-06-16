
//Hue, Saturation, Luminosity
static const u16 gBgFadeColors[BG_FADE_NUM][5] =
{
    //   TYPE                  H    S    L     blend coeff            H    S    L
    //                       /255 /255 /255     and color            deg   %    %
    [BG_FADE_NONE] =        {   0,   0,   0,   0, RGB_WHITE },  // { ---, ---, --- }
    [BG_FADE_GIRATINA] =    { 150,  20,   5,   8, RGB_BLACK },  // { ---, ---, --- }
};
