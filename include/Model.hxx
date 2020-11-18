/**
* Copyright (C) 2019, Ossyx
*/
#ifndef MODEL_HXX
#define MODEL_HXX

#include <vector>
#include <map>

#include "Common.hxx"
#include "Mesh.hxx"
#include "Material.hxx"

namespace rx
{

class Model
{
public:
  Model();

  ~Model();
  
  using MeshPtr = std::shared_ptr<Mesh>;

  void SetName(std::string const& p_name);

  void AddMesh(MeshPtr p_mesh);

  void AddMaterial(Material* p_material, std::string const& p_name);

  void AddMeshMaterialLink(unsigned int p_meshId, std::string const& p_materialName);

  unsigned int GetMeshCount();

  MeshPtr GetMesh(unsigned int p_idx);

  Material* GetMaterial(std::string const& p_name);

  Material* GetMaterialForMesh(unsigned int p_meshId);

  std::string GetName();


private:

  //Disable copy
  Model(Model const& p_other);

  std::string m_name;

  unsigned int m_meshCount;

  std::vector<MeshPtr> m_meshes;

  typedef std::map<std::string, Material*> MaterialMap;
  MaterialMap m_materials;

  typedef std::map<unsigned int, std::string> UintStringMap;
  UintStringMap m_meshToMaterialLink;
};

}

#endif
