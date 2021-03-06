#pragma once
#include <cstdint>
#include <iostream>

namespace My {
	struct GfxConfiguration {
		/// Inline all-elements constructor.
		/// \param[in] r the red color depth in bits
		/// \param[in] g the green color depth in bits
		/// \param[in] b the blue color depth in bits
		/// \param[in] a the alpha color depth in bits
		/// \param[in] d the depth buffer depth in bits
		/// \param[in] s the stencil buffer depth in bits
		/// \param[in] msaa the msaa sample count
		/// \param[in] width the screen width in pixel
		/// \param[in] height the screen height in pixel
		GfxConfiguration(int32_t r = 8, int32_t g = 8,
			int32_t b = 8, int32_t a = 8,
			int32_t d = 24, int32_t s = 0, int32_t msaa = 1,
			int32_t width = 1920, int32_t height = 1080, const char* app_name="GameEngineFromScratch") :
			redBits(r), greenBits(g), blueBits(b), alphaBits(a),
			depthBits(d), stencilBits(s), msaaSamples(msaa),
			screenWidth(width), screenHeight(height), appName(app_name)
		{
		}

		int32_t redBits; ///< red color channel depth in bits
		int32_t greenBits; ///< green color channel depth in bits
		int32_t blueBits; ///< blue color channel depth in bits
		int32_t alphaBits; ///< alpha color channel depth in bits
		int32_t depthBits; ///< depth buffer depth in bits
		int32_t stencilBits; ///< stencil buffer depth in bits
		int32_t msaaSamples; ///< MSAA samples
		int32_t screenWidth;
		int32_t screenHeight;
        static const int32_t kMaxInFlightFrameCount = 2;
        static const int32_t kMaxSceneObjectCount = 2048;
        static const int32_t kMaxTexturePerMaterialCount = 16;
        const char* appName;

        friend std::ostream& operator<<(std::ostream& out, const GfxConfiguration& conf)
        { 
            out << "App Name:" << conf.appName << std::endl;
            out << "GfxConfiguration:" << 
                " R:"  << conf.redBits << 
                " G:"  << conf.greenBits <<
                " B:"  << conf.blueBits <<
                " A:"  << conf.alphaBits <<
                " D:"  << conf.depthBits <<
                " S:"  << conf.stencilBits <<
                " M:"  << conf.msaaSamples <<
                " W:"  << conf.screenWidth <<
                " H:"  << conf.screenHeight <<
                std::endl;
            return out;
        }
	};
}

