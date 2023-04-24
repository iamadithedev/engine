#include "importer.hpp"

mesh_geometry<vertex::diffuse> Importer::load(const std::string& file)
{
    Assimp::Importer               importer;
    mesh_geometry<vertex::diffuse> geometry;

    const aiScene* scene = importer.ReadFile(file, 0);

    if (scene && scene->mRootNode)
    {
        const aiNode* node = scene->mRootNode->mChildren[0];

        for (uint32_t i = 0; i < node->mNumMeshes; i++)
        {
            const aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

            for (uint32_t j = 0; j < mesh->mNumVertices; j++)
            {
                const aiVector3D& position = mesh->mVertices[j];
                const aiVector3D& normal   = mesh->mNormals[j];

                geometry.vertices.push_back({{ position.x, position.y, position.z },
                                                      { normal.x, normal.y, normal.z }});
            }

            for (uint32_t j = 0; j < mesh->mNumFaces; j++)
            {
                const aiFace& face = mesh->mFaces[j];

                for (uint32_t f = 0; f < face.mNumIndices; f++)
                {
                    geometry.indices.push_back(face.mIndices[f]);
                }
            }
        }
    }

    return geometry;
}