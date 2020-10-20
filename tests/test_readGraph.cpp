#include <gtest/gtest.h>
#include "graph.h"

TEST(graph_test, graph_test_readGraph_1) {
	Graph* g = new Graph("./input/example.igraph");
	ASSERT_EQ(false, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_2) {
	Graph* g = new Graph("./input/err.igraph");
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_3) {
	Graph* g = new Graph("./input/err2.igraph");
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_4) {
	Graph* g = new Graph("./input/err3.igraph");
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_5) {
	Graph* g = new Graph("./input/err4.igraph");
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_6) {
	Graph* g = new Graph("./input/err_loop.igraph");
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_7) {
	Graph* g = new Graph("./input/err_parallel_edges.igraph");
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_8) {
	Graph* g = new Graph("./input/err_disconnected.igraph");
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_9) {
	Graph* g = new Graph("./input/err_nofile.igraph");
	ASSERT_EQ(true, g->fail());
	delete g;
}

