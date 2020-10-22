#include <gtest/gtest.h>
#include "graph.h"

TEST(graph_test, graph_test_readGraph_1) {
	Context cont;
	Graph* g = new Graph("./input/example.igraph", cont);
	ASSERT_EQ(false, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_2) {
	Context cont;
	Graph* g = new Graph("./input/err.igraph", cont);
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_3) {
	Context cont;
	Graph* g = new Graph("./input/err2.igraph", cont);
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_4) {
	Context cont;
	Graph* g = new Graph("./input/err3.igraph", cont);
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_5) {
	Context cont;
	Graph* g = new Graph("./input/err4.igraph", cont);
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_6) {
	Context cont;
	Graph* g = new Graph("./input/err_loop.igraph", cont);
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_7) {
	Context cont;
	Graph* g = new Graph("./input/err_parallel_edges.igraph", cont);
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_8) {
	Context cont;
	Graph* g = new Graph("./input/err_disconnected.igraph", cont);
	ASSERT_EQ(true, g->fail());
	delete g;
}

TEST(graph_test, graph_test_readGraph_9) {
	Context cont;
	Graph* g = new Graph("./input/err_nofile.igraph", cont);
	ASSERT_EQ(true, g->fail());
	delete g;
}

