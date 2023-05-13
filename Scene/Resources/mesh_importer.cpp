#include "mesh_importer.hpp"

std::vector<triangle_geometry> MeshImporter::load(const std::string& file)
{
    Assimp::Importer importer;

    auto scene = importer.ReadFile(file, 0);
    assert(scene != nullptr);

    const auto root = scene->mRootNode;
    assert(root != nullptr);

    std::vector<triangle_geometry> geometries;

    for (uint32_t i = 0; i < scene->mRootNode->mNumChildren; i++)
    {
        const auto node = scene->mRootNode->mChildren[i];

        for (uint32_t j = 0; j < node->mNumMeshes; j++)
        {
            const aiMesh* mesh = scene->mMeshes[node->mMeshes[j]];

            auto geometry = load(mesh);
            geometries.push_back(geometry);
        }
    }

    return geometries;
}

triangle_geometry MeshImporter::load(const aiMesh* mesh)
{
    triangle_geometry geometry;
    geometry.begin(mesh->mNumVertices, mesh->mNumFaces);

    for (uint32_t i = 0; i < mesh->mNumVertices; i++)
    {
        const aiVector3D& position = mesh->mVertices[i];
        const aiVector3D& normal   = mesh->mNormals[i];

        mesh_vertex::diffuse vertex {{ position.x, position.y, position.z },
                                     { normal.x, normal.y, normal.z }};
        geometry.add_vertex(vertex);
    }

    for (uint32_t i = 0; i < mesh->mNumFaces; i++)
    {
        const aiFace& face       = mesh->mFaces[i];
        assert(face.mNumIndices == primitive::triangle_count);

        geometry.add_face({ face.mIndices[0], face.mIndices[1], face.mIndices[2] });
    }

    geometry.end();
    return geometry;
}
