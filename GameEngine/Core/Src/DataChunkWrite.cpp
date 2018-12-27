

#include "DataChunkWrite.h"

NAMESPACEBEGIN(GameEngine)

DataChunkWrite::DataChunkWrite(uint32 dwBufferSize, bool bSkip0SizeChunk)
{
	mBufferSize = dwBufferSize;
	mpBuffer = new uint8[dwBufferSize];
	mOffset = 0;
	mbExternalMemory = false;
	mbSkip0SizeChunk = bSkip0SizeChunk;
}

DataChunkWrite::~DataChunkWrite()
{

}

uint32 DataChunkWrite::Write(void* pBuffer, uint32 dwBlockSize, uint32 dwBlockCount)
{
	if (mbExternalMemory)
	{
		if (mOffset + dwBlockSize * dwBlockCount > mBufferSize)
		{
			assert(false);
			return 0;
		}
	}
	else
	{
		while (mOffset + dwBlockSize * dwBlockCount > mBufferSize)
		{
			uint32 dwNewBufferSize = mBufferSize * 2;
			uint8* pbyNewBuffer = new uint8[dwNewBufferSize];
			memcpy(pbyNewBuffer, mpBuffer, min(mBufferSize, dwNewBufferSize));
			SAFE_DELETE_ARRAY(mpBuffer);
			mpBuffer = pbyNewBuffer;
			mBufferSize = dwNewBufferSize;
		}
	}

	uint8* pSrc = (uint8*)pBuffer;
	for (uint32 i = 0; i < dwBlockCount; i++)
	{
		memcpy(&mpBuffer[mOffset], pSrc, dwBlockSize);
		pSrc += dwBlockSize;
		mOffset += dwBlockSize;
	}

	return mOffset;
}

uint32 DataChunkWrite::StartChunk(uint32 dwName)
{
	ChunkDesc desc;
	desc.header.dwName = dwName;
	desc.header.dwSize = 0;
	desc.dwOffset = mOffset;
	mChunkDescStack.push(desc);

	Write(&desc.header, sizeof(ChunkHdr), 1);
	return 0;
}

uint32 DataChunkWrite::EndChunk(uint32 dwName)
{
	assert(!mChunkDescStack.empty());
	ChunkDesc desc = mChunkDescStack.top();
	mChunkDescStack.pop();

	assert(desc.header.dwName == dwName);
	if (desc.dwOffset > mBufferSize)
	{
		assert(false);
		return 0;
	}

	ChunkHdr* pHdr = (ChunkHdr*)&mpBuffer[desc.dwOffset];
	pHdr->dwSize = mOffset - (desc.dwOffset + sizeof(ChunkHdr));
	if (mbSkip0SizeChunk && pHdr->dwSize == 0)
		mOffset = desc.dwOffset;

	return 0;
}

uint32 DataChunkWrite::WriteInt(int i)
{
	return Write(&i, sizeof(int), 1);
}

uint32 DataChunkWrite::WriteString(char* str)
{
	uint32 dwOffset = WriteInt(strlen(str));
	if (strlen(str) > 0)
		return Write(str, strlen(str), 1);
	return dwOffset;
}

bool DataChunkWrite::SaveToFile(const char* pszFilename)
{
	assert(mChunkDescStack.empty());
	FILE* fp = NULL;
	fopen_s(&fp, pszFilename, "wb");
	if (!fp)
		return false;

	if (mOffset == 0)
		return false;

	fwrite(mpBuffer, mOffset, 1, fp);
	fclose(fp);
	return true;
}

void DataChunkWrite::Destroy()
{
	if (mbExternalMemory)
	{
		mpBuffer = NULL;
	}
	else
	{
		SAFE_DELETE_ARRAY(mpBuffer);
	}

	mBufferSize = 0;
	mOffset = 0;
}

NAMESPACEEND