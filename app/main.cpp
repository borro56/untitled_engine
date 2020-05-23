#include "../engine/include/Components/Translation.h"
#include "../engine/include/Components/Health.h"
#include "../engine/include/ECS/EntityManager.h"
#include "include/TestSystem.h"



int main ()
{
    EntityManager em;
    em.Create(Translation(Vector3(25,1,1)), Health(1));
    em.Create(Translation(Vector3(32,1,1)), Health(7));
    em.Create(Health(1), Translation(Vector3(77,1,1)) );
    em.Create(Translation(Vector3(97,1,1)) );

    em.GetOrCreateSystem<TestSystem>();

    //TODO: Improve this
    auto threads = em.ExecuteSystems();
    for(auto thread : threads)
    {
        thread->Thread().join();
    }


    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;


}