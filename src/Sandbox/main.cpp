#include <GEPengine/GEPengine.h>
#include <iostream>

#define shared std::shared_ptr
#define weak std::weak_ptr

const char* src =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec3 a_Position;                    \n" \
"attribute vec2 a_TexCoord;                    \n" \
"                                              \n" \
"uniform mat4 u_Projection;                    \n" \
"                                              \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  vec3 pos = a_Position + vec3(0, 0, -5);     \n" \
"  gl_Position = u_Projection * vec4(pos, 1);  \n" \
"  v_TexCoord = a_TexCoord;                    \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n" \
"#ifdef FRAGMENT                               \n" \
"                                              \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_FragColor = vec4(v_TexCoord, 0, 1);      \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n";

const char* obj =
"v -1 1 0           \n" \
"v -1 -1 0          \n" \
"v 1 -1 0           \n" \
"v 1 1 0            \n" \
"                   \n" \
"vt 0 1             \n" \
"vt 0 0             \n" \
"vt 1 0             \n" \
"vt 1 1             \n" \
"                   \n" \
"f 1/1 2/2 3/3 4/4  \n" \
"                   \n";

void main ()
{
	shared<Core> core = Core::Initialize();
	
	shared<Object> entity = core->AddObject();
	shared<MeshRenderer> rend = entity->AddComponent<MeshRenderer>();

	shared<Shader> shader = core->GetResources()->Load<Shader>("Shaders\\ObjShader.txt");
	shared<Material> mat = std::make_shared<Material>();
	mat->SetShader(shader);

	shared<Mesh> shape = core->GetResources()->Load<Mesh>("curuthers\\curuthers.obj");
	           
	rend->SetMesh(shape);
	rend->SetMaterial(mat);
	 
	core->Start();
	return;
}