#ifndef CAMERA_H
#define CAMERA_H

/* 
 * Screen coords (x; y) locates at top-left corner,
 * World coords (x; y) locates at down-left corner.
 * When converting world Y to screen Y, pass in function y + h (top adge), not y,
 */

namespace Graphic
{
    class Camera
    {
    public:
        /* parameters specified in in-game block coordinates */
        Camera(float x, float y, float w, float h)
            : m_x { x }
            , m_y { y }
            , m_w { w }
            , m_h { h }
        {
        }

        /*
         * Scale specifier is used to scale objects on screen (obviously, huh?)
         * To calculate this parameter this formula is often used:
         * 
         * scale = logical size of surface where camera should render (or maybe width in pixels) / number of blocks that should render to the screen
         */
        void setBlockScale(int scale)
        {
            m_scale = scale;
        }

        int getBlockScale() { return m_scale; }
        float getHeight() { return m_h; }
        float getWidth() { return m_w; }

        void setPosition(float x, float y)
        {
            m_x = x;
            m_y = y;
        }

        int worldToScreenX(float x)
        {
            /* just simply x associated to screen position multiplied by scale specifier */
            return static_cast<int>((x - m_x) * m_scale);
        }

        int worldToScreenY(float y)
        {
            /*
             * A little more complex here.
             * First we get y associated to in-world camera's visible zone,
             * then we multiply this by scale specifier,
             * and finally we use formula for converting the cartesian y-axis to the matrix y-axis.
             * y-matrix = height - 1 - y-cartesian
             * 
             * NOTE: Cartesian is that one where y increases upward and matrix is that one where y increases downward (like in window surface).
             */
            return static_cast<int>(m_h - (y - m_y) * m_scale);
        }

        Camera(const Camera&) = delete;
        Camera& operator=(const Camera&) = delete;

    private:
        float m_x {};
        float m_y {};
        float m_w {};
        float m_h {};

        int m_scale {};
    };
}

#endif