#ifndef ParticleEmitter_H
#define ParticleEmitter_H
#include "../Math/Randomizer.h";
#include "../Rendering/SceneGraph.h";
#include "Particle.h";




class ParticleEmitter
{
public:

    //not using texture ID
    int numberOfParticles;
    float lowNumber, highNumber;
    GLuint shaderProgramName;
    ParticleEmitter(int numberOfParticles_, std::string shaderProgramName_);
    void Update(const float deltaTime_);
    void Render(Camera* camera_, std::vector<Particle*> VectorParticles_);
    float RNG();
private:
    std::vector<Particle*> VectorParticles;
};

#endif