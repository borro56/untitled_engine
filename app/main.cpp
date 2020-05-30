#include "../engine/include/ECS/Components/Translation.h"
#include "include/Components/Health.h"
#include "../engine/include/ECS/EntityManager.h"
#include "../engine/include/Render/RenderSystem.h"


int main()
{
    EntityManager em;
    em.Create(Translation(Vector3(25,1,1)), Health(1));
    //em.Create(Translation(Vector3(32,1,1)), Health(7));
    //em.Create(Health(1), Translation(Vector3(77,1,1)) );
    //em.Create(Translation(Vector3(97,1,1)) );

    shared_ptr<RenderSystem> app = em.GetOrCreateSystem<RenderSystem>();

    while(!glfwWindowShouldClose(app->window)) {
        em.ExecuteSystems();
    }

    return EXIT_SUCCESS;
}

void ecsTest()
{

    /*while(true)
    {
        em.ExecuteSystems();
    }*/

    /*
    try {
        app->run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }*/
}

void glfwTest()
{

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

}

