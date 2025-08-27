#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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

    int loadModel(const std::string &filePath)
    {
        std::ifstream inputFile(filePath);

        if (!inputFile.is_open())
        {
            std::cerr << "Не удалось открыть файл!\n";
            return 1;
        }

        std::string line;
        std::vector<Vertex> vertices;
        std::vector<Faces> faces;

        while (std::getline(inputFile, line))
        {
            if (!line.empty())
            {
                std::stringstream ss(line);
                std::string type;
                ss >> type;

                if (type == "v")
                {
                    Vertex v;
                    ss >> v.x >> v.y >> v.z;
                    vertices.push_back(v);
                }
                if (type == "f")
                {
                    Faces f;
                    int vertex_index;
                    while (ss >> vertex_index)
                    {
                        f.vertices.push_back(vertex_index);
                    }
                }
            }
        }
    }
}