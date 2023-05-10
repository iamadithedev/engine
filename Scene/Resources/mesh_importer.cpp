#include "mesh_importer.hpp"

std::vector<triangle_geometry> MeshImporter::load(const std::string& file)
{
    Assimp::Importer  importer;
    std::vector<triangle_geometry> geometries;

    auto scene = importer.ReadFile(file, 0);
    assert(scene != nullptr);

    const auto root = scene->mRootNode;
    assert(root != nullptr);

    for (int32_t n = 0; n < scene->mRootNode->mNumChildren; n++)
    {
        const auto node = scene->mRootNode->mChildren[n];

        for (uint32_t i = 0; i < node->mNumMeshes; i++)
        {
            const aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

            auto geometry = load(mesh);
            geometries.push_back(geometry);
        }
    }

    return geometries;
}

triangle_geometry MeshImporter::load(const aiMesh* mesh)
{
    triangle_geometry geometry;
    geometry.begin();

    for (uint32_t j = 0; j < mesh->mNumVertices; j++)
    {
        const aiVector3D& position = mesh->mVertices[j];
        const aiVector3D& normal   = mesh->mNormals[j];

        mesh_vertex::diffuse vertex {{ position.x, position.y, position.z },
                                     { normal.x, normal.y, normal.z }};

        geometry.add_vertex(vertex);
    }

    for (uint32_t j = 0; j < mesh->mNumFaces; j++)
    {
        const aiFace& face = mesh->mFaces[j];
        assert(face.mNumIndices == 3);

        geometry.add_face({ face.mIndices[0], face.mIndices[1], face.mIndices[2] });
    }

    geometry.end();
    return geometry;
}
