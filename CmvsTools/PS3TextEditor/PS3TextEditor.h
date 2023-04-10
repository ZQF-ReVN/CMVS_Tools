#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>


struct PS3HEADER
{
	uint32_t dwSignature;
	uint32_t dwHeaderLen;
	uint32_t dwUnknown0;
	uint32_t dwKey;
	uint32_t dwTextCount;
	uint32_t dwCodeBlockLen;
	uint32_t dwUnknown1;
	uint32_t dwTextBlockLen;
	uint32_t dwUnknown2;
	uint32_t dwCompressSize;
	uint32_t dwDecompressSize;
	uint32_t dwUnknown3;
};

struct PS3INFO
{
	uint32_t pPS3File;
	uint32_t pCodeBlock;
	uint32_t pTextBlock;
	uint32_t dwCodeBlockLen;
};

class PS3TextEditor
{
private:


public:
	PS3TextEditor();
	~PS3TextEditor();

	PS3INFO m_PS3Info;
	PS3HEADER m_Header;
	byte m_abFlagPushStr[4];

	virtual bool GetPS3FileInfo() = 0;

};

class PS3TextDump : public PS3TextEditor
{
private:
	bool m_isFullText;
	FILE* m_fpTextFile;
	uint32_t m_dwCodePage;
	std::wstring m_wsPath;
	std::vector<uint32_t> m_vecppStr;

	bool GetPS3FileInfo();
	void SearchOffset();
	bool CreateDumpFile();
	void DumpText();

public:
	PS3TextDump(std::wstring& wsPath, uint32_t dwCodePage, bool isFullText);
	~PS3TextDump();

};

class PS3TextInset : public PS3TextEditor
{
private:
	FILE* m_fpPS3File;
	uint32_t m_dwCodePage;
	uint32_t m_countInset;
	std::wstring m_wsTextPath;
	std::wstring m_wsPS3FilePath;

	bool GetPS3FileInfo();
	bool InsetTextFile();

public:
	PS3TextInset(std::wstring& wsPath, uint32_t dwCodePage);
	~PS3TextInset();

};
