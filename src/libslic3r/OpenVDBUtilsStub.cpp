///|/ WoA-PoC: stub implementations of the OpenVDB-backed API in OpenVDBUtils.hpp.
///|/ Compiled in lieu of OpenVDBUtils.cpp when OpenVDB isn't built (e.g. on
///|/ Windows-on-ARM where OpenVDB / OpenEXR don't currently compile cleanly).
///|/ The stubs throw at runtime — SLA hollow generation and CSG voxelization
///|/ are not functional in this configuration.
///|/
#include "OpenVDBUtils.hpp"

#include <stdexcept>

namespace Slic3r {

struct VoxelGrid {};

void VoxelGridDeleter::operator()(VoxelGrid *ptr) { delete ptr; }

template<> VoxelGridPtr make_voxelgrid<>()
{
    return VoxelGridPtr{nullptr};
}

void reset_accessor(const VoxelGrid &) {}

double get_distance_raw(const Vec3f &, const VoxelGrid &)
{
    throw std::runtime_error("OpenVDB support is not compiled in (Windows-on-ARM build).");
}

float get_voxel_scale(const VoxelGrid &) { return 1.f; }

VoxelGridPtr clone(const VoxelGrid &) { return VoxelGridPtr{nullptr}; }

VoxelGridPtr mesh_to_grid(const indexed_triangle_set &, const MeshToGridParams &)
{
    throw std::runtime_error("OpenVDB support is not compiled in (Windows-on-ARM build).");
}

indexed_triangle_set grid_to_mesh(const VoxelGrid &, double, double, bool)
{
    throw std::runtime_error("OpenVDB support is not compiled in (Windows-on-ARM build).");
}

VoxelGridPtr dilate_grid(const VoxelGrid &, float, float) { return VoxelGridPtr{nullptr}; }

VoxelGridPtr redistance_grid(const VoxelGrid &, float) { return VoxelGridPtr{nullptr}; }

VoxelGridPtr redistance_grid(const VoxelGrid &, float, float, float)
{
    return VoxelGridPtr{nullptr};
}

void rescale_grid(VoxelGrid &, float) {}

void grid_union(VoxelGrid &, VoxelGrid &) {}
void grid_difference(VoxelGrid &, VoxelGrid &) {}
void grid_intersection(VoxelGrid &, VoxelGrid &) {}

bool is_grid_empty(const VoxelGrid &) { return true; }

} // namespace Slic3r
