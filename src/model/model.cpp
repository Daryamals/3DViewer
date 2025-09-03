#include "model.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace s21
{
    const std::vector<Vertex> &Model::getVertices() const
    {
        return vertices_;
    }

    const std::vector<Faces> &Model::getFaces() const
    {
        return faces_;
    }
    s21::Model Model::loadFromFile(const std::string &filePath)
    {
        s21::Model model;
        std::ifstream inputFile(filePath);

        if (!inputFile.is_open())
        {
            std::cerr << "Не удалось открыть файл!\n"
                      << filePath << std::endl;
            return model;
        }

        std::string line;

        while (std::getline(inputFile, line))
        {
            if (line.empty())
            {
                continue;
            }

            std::stringstream ss(line);
            std::string type;
            ss >> type;

            if (type == "v")
            {
                Vertex v;
                ss >> v.x >> v.y >> v.z;
                model.vertices_.push_back(v);
            }
            if (type == "f")
            {
                Faces f;
                int vertex_index;
                while (ss >> vertex_index)
                {
                    f.vertices.push_back(vertex_index - 1);
                }
                model.faces_.push_back(f);
            }
        }
        std::cout << "Модель загружена: " << filePath << std::endl;
        std::cout << "Вершин: " << model.getVertices().size() << std::endl;
        std::cout << "Полигонов: " << model.getFaces().size() << std::endl;

        return model;
    }
}