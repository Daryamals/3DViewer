#include <vector>
#include <string>
#ifndef MODEL_H_
#define MODEL_H_

namespace s21
{

    struct Vertex
    {
        double x;
        double y;
        double z;
    };

    struct Faces
    {
        std::vector<int> vertices;
    };

    class Model
    {
    public:
        Model() = default;
        Model(const std::vector<Vertex> &vertices, const std::vector<Faces> &faces);

        const std::vector<Vertex> &getVertices() const;
        const std::vector<Faces> &getFaces() const;

        static Model loadFromFile(const std::string &filePath);

    private:
        std::vector<Vertex> vertices_;
        std::vector<Faces> faces_;
    };
}

#endif