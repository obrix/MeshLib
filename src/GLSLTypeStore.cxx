#include "GLSLTypeStore.hxx"

namespace rx
{

GLSLTypeStore::GLSLTypeStore()
{
}

GLSLTypeStore::~GLSLTypeStore()
{
}

std::set<std::string> const& GLSLTypeStore::GetMembers() const
{
  return mMembers;
}

template <>
MeshLib_EXPORT float GLSLTypeStore::Get<float>(std::string const& pKey) const
{
  return mFloats.at(pKey);
}

template <>
MeshLib_EXPORT int GLSLTypeStore::Get<int>(std::string const& pKey) const
{
  return mInts.at(pKey);
}

template <>
MeshLib_EXPORT glm::vec2 GLSLTypeStore::Get<glm::vec2>(std::string const& pKey) const
{
  return mVec2s.at(pKey);
}

template <>
MeshLib_EXPORT glm::vec3 GLSLTypeStore::Get<glm::vec3>(std::string const& pKey) const
{
  return mVec3s.at(pKey);
}

template <>
MeshLib_EXPORT glm::vec4 GLSLTypeStore::Get<glm::vec4>(std::string const& pKey) const
{
  return mVec4s.at(pKey);
}

template <>
MeshLib_EXPORT glm::mat4 GLSLTypeStore::Get<glm::mat4>(std::string const& pKey) const
{
  return mMat4s.at(pKey);
}

template <>
MeshLib_EXPORT void GLSLTypeStore::Set(std::string const& pKey, float pValue)
{
  mMembers.insert(pKey);
  mFloats[pKey] = pValue;
}

template <>
MeshLib_EXPORT void GLSLTypeStore::Set(std::string const& pKey, int pValue)
{
  mMembers.insert(pKey);
  mInts[pKey] = pValue;
}

template <>
MeshLib_EXPORT void GLSLTypeStore::Set(std::string const& pKey, glm::vec2 pValue)
{
  mMembers.insert(pKey);
  mVec2s[pKey] = pValue;
}

template <>
MeshLib_EXPORT void GLSLTypeStore::Set(std::string const& pKey, glm::vec3 pValue)
{
  mMembers.insert(pKey);
  mVec3s[pKey] = pValue;
}

template <>
MeshLib_EXPORT void GLSLTypeStore::Set(std::string const& pKey, glm::vec4 pValue)
{
  mMembers.insert(pKey);
  mVec4s[pKey] = pValue;
}


template <>
MeshLib_EXPORT void GLSLTypeStore::Set(std::string const& pKey, glm::mat4 pValue)
{
  mMembers.insert(pKey);
  mMat4s[pKey] = pValue;
}

template <>
MeshLib_EXPORT bool GLSLTypeStore::Has<float>(std::string const& pKey) const
{
  return mFloats.find(pKey) != mFloats.end();
}

template <>
MeshLib_EXPORT bool GLSLTypeStore::Has<int>(std::string const& pKey) const
{
  return mInts.find(pKey) != mInts.end();
}

template <>
MeshLib_EXPORT bool GLSLTypeStore::Has<glm::vec2>(std::string const& pKey) const
{
  return mVec2s.find(pKey) != mVec2s.end();
}

template <>
MeshLib_EXPORT bool GLSLTypeStore::Has<glm::vec3>(std::string const& pKey) const
{
  return mVec3s.find(pKey) != mVec3s.end();
}

template <>
MeshLib_EXPORT bool GLSLTypeStore::Has<glm::vec4>(std::string const& pKey) const
{
  return mVec4s.find(pKey) != mVec4s.end();
}

template <>
MeshLib_EXPORT bool GLSLTypeStore::Has<glm::mat4>(std::string const& pKey) const
{
  return mMat4s.find(pKey) != mMat4s.end();
}

}
