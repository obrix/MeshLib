/**
* Copyright (C) 2019, Ossyx
*/
#include "Material.hxx"
namespace rx
{

Material::Material():
m_name("")
{
}

Material::~Material()
{
}

std::string Material::GetName() const
{
  return m_name;
}

std::filesystem::path Material::GetDirectory() const
{
  return m_directory;
}

void Material::SetName(std::string const& p_name)
{
  m_name = p_name;
}

void Material::SetDirectory(const std::filesystem::path& p_path)
{
  m_directory = p_path;
}

void Material::SetData(std::string const& p_name, Material::ByteTexture p_data)
{
  m_ucharTextures[p_name] = p_data;
}

void Material::SetData(std::string const& p_name, Material::FloatTexture p_data)
{
  m_floatTextures[p_name] = p_data;
}

void Material::SetData(std::string const& p_name, Material::UShortTexture p_data)
{
  m_ushortTextures[p_name] = p_data;
}

void Material::SetUniformData(std::string const& p_uniform, std::string const& p_attributeKey)
{
  m_uniforms[p_uniform] = p_attributeKey;
}

void Material::SetShaderName(std::string const& p_name)
{
  m_shaderName = p_name;
}

bool Material::GetUniformData(std::string const& p_uniform, std::string& p_attributeKey) const
{
  StringMap::const_iterator it = m_uniforms.find(p_uniform);
  if (it != m_uniforms.cend())
  {
    p_attributeKey = it->second;
    return true;
  }
  return false;
}

Material::StringMap const& Material::GetUniforms() const
{
  return m_uniforms;
}

std::string Material::GetShaderName() const
{
  return m_shaderName;
}

template <>
std::shared_ptr<Texture<unsigned char>> Material::GetTextureData(std::string const& pName) const
{
  ByteTextureMap::const_iterator it = m_ucharTextures.find(pName);
  assert(it != m_ucharTextures.cend());
  return it->second;
}

template <>
std::shared_ptr<Texture<unsigned short>> Material::GetTextureData(std::string const& pName) const
{
  UShortTextureMap::const_iterator it = m_ushortTextures.find(pName);
  assert(it != m_ushortTextures.cend());
  return it->second;
}

template <>
std::shared_ptr<Texture<float>> Material::GetTextureData(std::string const& pName) const
{
  FloatTextureMap::const_iterator it = m_floatTextures.find(pName);
  assert(it != m_floatTextures.cend());
  return it->second;
}

template <>
bool Material::HasTextureData<unsigned char>(std::string const& pName) const
{
  ByteTextureMap::const_iterator it = m_ucharTextures.find(pName);
  return it != m_ucharTextures.cend();
}

template <>
bool Material::HasTextureData<float>(std::string const& pName) const
{
  return m_floatTextures.find(pName) != m_floatTextures.end();
}

template <>
bool Material::HasTextureData<unsigned short>(std::string const& pName) const
{
  return m_ushortTextures.find(pName) != m_ushortTextures.end();
}

}
