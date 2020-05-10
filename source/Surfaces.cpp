#include "Surfaces.h"

Surfaces::Surfaces()
{
    m_textures[1] = LoadPixels(REDBRICK_TEXTURE_FILEPATH);
    m_textures[2] = LoadPixels(PURPLESTONE_TEXTURE_FILEPATH);
    m_textures[3] = LoadPixels(MOSSYSTONE_TEXTURE_FILEPATH);
    m_textures[4] = LoadPixels(GRAYSTONE_TEXTURE_FILEPATH);
    m_textures[5] = LoadPixels(COLORSTONE_TEXTURE_FILEPATH);
    m_textures[6] = LoadPixels(BLUESTONE_TEXTURE_FILEPATH);
    m_textures[7] = LoadPixels(WOOD_TEXTURE_FILEPATH);
    m_textures[8] = LoadPixels(EAGLE_TEXTURE_FILEPATH);
}

uint32_t Surfaces::GetPixel(uint32_t* pixels, int x, int y)
{
    return pixels[(y * TEXTURE_WIDTH) + x];
}


int Surfaces::Darken(int color, float amount)
{
    amount = 1.0f - amount;
    auto a = (color >> 24) & 0xFF;
    auto r = static_cast<int>(((color >> 16) & 0xFF) * amount);
    auto g = static_cast<int>(((color >> 8) & 0xFF) * amount);
    auto b = static_cast<int>((color & 0xFF) * amount);

    return (a << 24) | (r << 16) | (g << 8) | b;
}

uint32_t* Surfaces::LoadPixels(const char* filePath)
{
    auto image = IMG_Load(filePath);
    auto pixels = static_cast<uint32_t*>(image->pixels);
	
    return pixels;
}
