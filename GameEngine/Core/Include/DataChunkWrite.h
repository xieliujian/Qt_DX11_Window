
#ifndef __DataChunkWrite_h__
#define __DataChunkWrite_h__

#include "Prerequest.h"

NAMESPACEBEGIN(GameEngine)

class DataChunkWrite
{
public:
	DataChunkWrite(uint32 dwBufferSize, bool bSkip0SizeChunk = true);
	~DataChunkWrite();

	struct ChunkHdr
	{
		uint32 dwName;
		uint32 dwSize;
	};

	struct ChunkDesc
	{
		ChunkHdr header;
		uint32 dwOffset;
	};

	uint32 StartChunk(uint32 dwName);
	uint32 EndChunk(uint32 dwName);
	uint32 Write(void* pBuffer, uint32 dwBlockSize, uint32 dwBlockCount);
	uint32 WriteChar(char s) { return Write(&s, sizeof(char), 1); }
	uint32 WriteDWORD(uint32 dw) { return Write(&dw, sizeof(uint32), 1); }
	uint32 WriteInt(int i);
	uint32 WriteFloat(float f){ return Write(&f, sizeof(float), 1); }
	uint32 WriteShort(short s){ return Write(&s, sizeof(short), 1); }
	uint32 WriteByte(uint8 b){ return Write(&b, sizeof(uint8), 1); }
	uint32 WriteString(char* str);
	bool SaveToFile(const char* pszFilename);
	void Destroy();
protected:
	std::stack<ChunkDesc> mChunkDescStack;
	uint32	mBufferSize;
	uint8*	mpBuffer;
	uint32	mOffset;
	bool	mbSkip0SizeChunk;		// 是否skip没有内容的文件头
	bool	mbExternalMemory;		// 是否自建内存
};

NAMESPACEEND

#endif