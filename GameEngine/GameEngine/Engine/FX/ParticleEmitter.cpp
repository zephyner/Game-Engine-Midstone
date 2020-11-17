#include "ParticleEmitter.h"
#include "../Core/CoreEngine.h"
using namespace MATH;

ParticleEmitter::ParticleEmitter(int numberOfParticles_, std::string shaderProgramName_)
{
    //random number range 
    lowNumber = 0.0f;
    highNumber = 100.0f;
    numberOfParticles = numberOfParticles_;
    //need to fix 
    shaderProgramName = ShaderHandler::GetInstance()->GetShader(shaderProgramName_);
    //need to fix 
    if (ShaderHandler::GetInstance()->GetShader(shaderProgramName_) == 0)
    {
        Debug::Error("Particles not rendered because no shader found: ", "ParticleEmitter.h", __LINE__);
        return;
    }
    else
    {

        //reserved space 
        VectorParticles.reserve(numberOfParticles_);
        for (int i = 0; i < numberOfParticles; i++)
        {
            VectorParticles.push_back(new Particle(shaderProgramName));
            float ranNum = RNG();
            VectorParticles[i]->Lifetime = RNG();
        }
    }
}

void ParticleEmitter::Render(Camera* camera_, std::vector<Particle*> VectorParticles_)
{
    for (int i = 0; i < VectorParticles.size(); i++)
    {
        glUseProgram(shaderProgramName);
        VectorParticles[i]->Render(camera_);
    }
}

//fix this update part for deltatime and Lifetime
void ParticleEmitter::Update(const float deltaTime_)
{
    for (int i = 0; i < numberOfParticles; i++)
    {
        if (VectorParticles[i]->Lifetime <= 0)
        {
            delete VectorParticles[i];
            //delete first
            VectorParticles.erase(VectorParticles.begin() + i);
        }
        VectorParticles[i]->Position = glm::vec3(RNG(), RNG(), 0);
    }
}


float ParticleEmitter::RNG()
{

    Randomizer random;
    return random.rand(lowNumber, highNumber);
}