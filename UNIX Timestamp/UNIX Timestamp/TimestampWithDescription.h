#pragma once
#include "Timestamp.h"


class TimestampWithDescription : public Timestamp
{
	char* description = nullptr;

	void free();
	void copyFrom(const TimestampWithDescription& other);
	void moveFrom(TimestampWithDescription&& other);

public:
	TimestampWithDescription();
	TimestampWithDescription(int seconds, const char* description);
	TimestampWithDescription(const TimestampWithDescription& other);
	TimestampWithDescription(TimestampWithDescription&& other) noexcept;
	TimestampWithDescription& operator=(const TimestampWithDescription& other);
	TimestampWithDescription& operator=(TimestampWithDescription&& other) noexcept;
	~TimestampWithDescription();

	void setDescription(const char* description);
	const char* getDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& timestampwithdescription);
	friend std::istream& operator>>(std::istream& is, TimestampWithDescription& timestampwithdescription);

};

