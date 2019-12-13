#include "mathutil.h"

#include <sr1/vector>
#include <sr1/memory>
#include <string>

namespace rend
{
	struct Buffer;
	struct Context;
	struct Shader;
	struct TextureAdapter;
	struct Face;

	struct CollitionFace //MT
	{
		vec3 pa;
		vec3 pb;
		vec3 pc;
	};

	struct Extent //MT
	{
		vec3 min;
		vec3 max;
	};

	struct BufferData
	{
		std::string name;
		std::sr1::shared_ptr<Buffer> buffer;
	};

	struct TextureData
	{
		std::string name;
		std::sr1::shared_ptr<TextureAdapter> texture;
	};

	struct Mesh
	{
		void setBuffer(const std::string& name, const std::sr1::shared_ptr<Buffer>& buffer);
		void setTexture(const std::string& name, const std::sr1::shared_ptr<TextureAdapter>& texture);
		void parse(const std::string& data);

		std::vector<CollitionFace>& getTriangles() { return triangles; } //MT
		Extent& getExtent() { return extent; } //MT

	private:
		friend struct Context;
		friend struct Shader;

		std::sr1::shared_ptr<Context> context;
		std::sr1::vector<std::sr1::shared_ptr<BufferData> > buffers;
		std::sr1::vector<std::sr1::shared_ptr<TextureData> > textures;

		void safeParse(const std::string& data, std::string& currentLine);

		void Mesh::generateExtent(std::vector<Face> faces); //MT
		std::vector<CollitionFace> triangles;//MT
		Extent extent;//MT
	};

}
