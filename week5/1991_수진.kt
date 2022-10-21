data class Node(val data: String, var left: Node?, var right: Node?)

fun main() {
    val n = readln().toInt()

    val (parent, left, right) = readln().split(" ")
    val root = Node(parent, null, null)
    if (left != ".")
        root.left = Node(left, null, null)
    if (right != ".")
        root.right = Node(right, null, null)


    for (i in 1 until n) {
        val (parent, left, right) = readln().split(" ")
        makeTree(root, parent, left, right)
    }

    preOrder(root)
    println()
    inOrder(root)
    println()
    postOrder(root)
    println()
}

private fun makeTree(root: Node, data: String, left: String, right: String) {
    if (root.data == data) {
        if (left != ".") root.left = Node(left, null, null)
        if (right != ".") root.right = Node(right, null, null)
    }
    else {
        if (root.left != null) makeTree(root.left!!, data, left, right)
        if (root.right != null) makeTree(root.right!!, data, left, right)
    }
}

private fun preOrder(root: Node) {
    print(root.data)
    root.left?.let { preOrder(it) }
    root.right?.let { preOrder(it) }
}

private fun inOrder(root: Node) {
    root.left?.let { inOrder(it) }
    print(root.data)
    root.right?.let { inOrder(it) }
}

private fun postOrder(root: Node) {
    root.left?.let { postOrder(it) }
    root.right?.let { postOrder(it) }
    print(root.data)
}
