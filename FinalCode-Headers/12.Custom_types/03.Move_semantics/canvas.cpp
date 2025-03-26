#include "canvas.h"
#include <stdexcept>
#include <utility>
#include <fmt/format.h>

namespace raw
{

    Canvas::Canvas(std::size_t width, std::size_t height)
        : m_width{width}, m_height{height} {
        m_pixels = new Pixel*[m_width];
        for (std::size_t i = 0; i < m_width; ++i) {
            m_pixels[i] = new Pixel[m_height];
        }
    }


    //Copy constructor
    Canvas::Canvas(const Canvas& src)
        : Canvas(src.m_width, src.m_height) {
        for (std::size_t i = 0; i < m_width; ++i) {
            for (std::size_t j = 0; j < m_height; ++j) {
                m_pixels[i][j] = src.m_pixels[i][j];
            }
        }
    }

    //Move constructor
    /*
    Canvas::Canvas(Canvas&& other) noexcept
        : m_width{other.m_width}, m_height{other.m_height}, m_pixels{other.m_pixels} {
        other.m_width = 0;
        other.m_height = 0;
        other.m_pixels = nullptr;
    }
    */

    //Move constructor in terms of std::exchange
    Canvas::Canvas(Canvas&& other) noexcept
        : m_width{std::exchange(other.m_width, 0)},
          m_height{std::exchange(other.m_height, 0)},
          m_pixels{std::exchange(other.m_pixels, nullptr)} 
    {
        fmt::println("Canvas move constructor called");
    }

    //Move constructor in terms of the swap method
    /*
    Canvas::Canvas(Canvas&& other) noexcept{
        fmt::println("Move constructor");
        swap(other); // Steal the data from other and let it die.
    }
    */

    Canvas::~Canvas() {
        for (std::size_t i = 0; i < m_width; ++i) {
            delete[] m_pixels[i];
        }
        delete[] m_pixels;
        fmt::println("Canvas destroyed");
    }

    //Copy assignment operator with the copy and swap idiom
    Canvas& Canvas::operator=(const Canvas& rhs) {
        fmt::println("Canvas copy assignment operator called");
        Canvas temp(rhs);
        swap(temp);
        return *this;
    }

    //Move assignment operator in terms of std::exchange
    Canvas& Canvas::operator=(Canvas&& other) noexcept {
        fmt::println("Canvas move assignment operator called");
        if (this != &other) {
            // Free the existing resource
            for (std::size_t i = 0; i < m_width; ++i) {
                delete[] m_pixels[i];
            }
            delete[] m_pixels;

            // Move the data using std::exchange
            m_width = std::exchange(other.m_width, 0);
            m_height = std::exchange(other.m_height, 0);
            m_pixels = std::exchange(other.m_pixels, nullptr);
        }
        return *this;
    }

    void Canvas::modify_pixel(std::size_t x, std::size_t y, const Pixel& pixel) {
        verify_coordinate(x, y);
        m_pixels[x][y] = pixel;
    }

    Pixel& Canvas::retrieve_pixel(std::size_t x, std::size_t y) {
        verify_coordinate(x, y);
        return m_pixels[x][y];
    }

    void Canvas::swap(Canvas& other) noexcept {
        std::swap(m_width, other.m_width);
        std::swap(m_height, other.m_height);
        std::swap(m_pixels, other.m_pixels);
    }

    void Canvas::print() const {    
        for (std::size_t y = 0; y < m_height; ++y) {
            for (std::size_t x = 0; x < m_width; ++x) {
                const Pixel& pixel = m_pixels[y][x];
                auto color = pixel.get_color();
                fmt::print("#{0:06X} ", color);
            }
            fmt::print("\n");
        }
    }

    void Canvas::verify_coordinate(std::size_t x, std::size_t y) const {
        if (x >= m_width || y >= m_height) {
            throw std::out_of_range("Invalid coordinate");
        }
    }

    void swap(Canvas& first, Canvas& second) noexcept {
        first.swap(second);
    }
    
} // namespace raw


namespace modern
{
    Canvas::Canvas(std::size_t width, std::size_t height)
        : m_width(width), m_height(height), m_pixels(width, std::vector<Pixel>(height)) {}

    void Canvas::modify_pixel(std::size_t x, std::size_t y, const Pixel& pixel) {
        verify_coordinate(x, y);
        m_pixels[x][y] = pixel;
    }

    Pixel& Canvas::retrieve_pixel(std::size_t x, std::size_t y) {
        verify_coordinate(x, y);
        return m_pixels[x][y];
    }


    void Canvas::print() const {
        for (const auto& row : m_pixels) {
            for (const auto& pixel : row) {
                fmt::print("{:06X} ", pixel.get_color());
            }
            fmt::print("\n");
        }
    }

    void Canvas::verify_coordinate(std::size_t x, std::size_t y) const {
        if (x >= m_width || y >= m_height) {
            throw std::out_of_range("Coordinate out of range");
        }
    }
    
} // namespace modern




