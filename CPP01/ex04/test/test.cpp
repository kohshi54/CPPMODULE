#include <gtest/gtest.h>
#include "MyFstream.hpp"

TEST(MyFstreamConstructorTest, FileIsOpenAfterConstruction) {
    MyFstream testStream("test/testfile/test0.txt", std::ios::in);
    
    EXPECT_TRUE(testStream.is_open());
    testStream.close();
}

TEST(MyFstreamConstructorTest, FilenameAttributeIsSetCorrectly) {
    const std::string expectedFilename = "test/testfile/test0.txt";

    MyFstream testStream(expectedFilename, std::ios::in);

    EXPECT_EQ(expectedFilename, testStream.getFilename());
    testStream.close();
}

TEST(MyFstreamTest, ReplaceWordInFileTest0) {
    MyFstream testIn("test/testfile/test0.txt", std::ios::in);
    MyFstream testOut("test/outfile/test0.txt", std::ios::out | std::ios::trunc);
    testIn.replaceWordInFile(testOut, "World", "Kohshi");
    EXPECT_EQ(0, system("diff test/outfile/test0.txt test/expected/test0.txt"));
}

TEST(MyFstreamTest, ReplaceWordInFileTest1) {
    MyFstream testIn("test/testfile/test1.txt", std::ios::in);
    MyFstream testOut("test/outfile/test1.txt", std::ios::out | std::ios::trunc);
    testIn.replaceWordInFile(testOut, "World", "Kohshi");
    EXPECT_EQ(0, system("diff test/outfile/test1.txt test/expected/test1.txt"));
}

TEST(MyFstreamTest, ReplaceWordInFileTest2) {
    MyFstream testIn("test/testfile/test2.txt", std::ios::in);
    MyFstream testOut("test/outfile/test2.txt", std::ios::out | std::ios::trunc);
    testIn.replaceWordInFile(testOut, "World", "Kohshi");
    EXPECT_EQ(0, system("diff test/outfile/test2.txt test/expected/test2.txt"));
}

TEST(MyFstreamTest, ReplaceWordInFileTest3) {
    MyFstream testIn("test/testfile/test3.txt", std::ios::in);
    MyFstream testOut("test/outfile/test3.txt", std::ios::out | std::ios::trunc);
    testIn.replaceWordInFile(testOut, "World", "Kohshi");
    EXPECT_EQ(0, system("diff test/outfile/test3.txt test/expected/test3.txt"));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
