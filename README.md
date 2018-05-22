# Moro
## Status
### Completed



### In Progress
  - Graphics Engine
  - Physics Engine



### Required
  - Audio Engine
  - GUI (X/Y Grid that contains a camera, and allows the creation of objects with editable properties, via GUI and scripts)
  - Scripting




### Considered
  - Plugins
  - Asset Editor (Image editor, Audio editor, etc.)



# Documentation

## Math

### Vector2 Class
  - Holds two doubles (x, y)
  - Can be used for storing location, velocity, etc.

## Physics
  
### Rigid Body Class
  - Super-class for collider objects like AABB and KDOP

### AABB Class
  - A simple box-collider
  - Not oriented

### OBB Class
  - A simple box-collider
  - Is oriented

### k-DOP Class
  - Polytope with k vertices
  - Is oriented

### Convex Hull Class
  - Polytope with minimal vertices to create a convex hull
  - Is oriented


## Graphics

### Texture Class
  - Contains path to image file

