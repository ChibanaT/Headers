int Headers_createFonts(char *name, int size, Headers_color letterColor, int contour, Headers_color contourColor, Headers_Style style = NORMAL_STYLE)
{
    return game -> CreateNormalFont(name, size, style, letterColor, contour, contourColor);
}

int Headers_