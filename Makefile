HEADERS = wallet.h strategy.h dataReader.h analytics.h model.h
SRCS = main.cpp wallet.cpp strategy.cpp dataReader.cpp analytics.cpp model.cpp

model : ${SRCS} ${HEADERS}
	g++ -std=c++17 ${SRCS} -o model