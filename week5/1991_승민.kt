val n = readln().toInt()

class Node(val elem: String) {
    var left: Node? = null
    var right: Node? = null
    fun printNode() {
        print(elem)
    }
    fun goLeft(): Node? {
        return left
    }
    fun goRight(): Node? {
        return right
    }
}

fun main() {
    val tree = mutableListOf<Node>()
    repeat(n) {
        val (e, l, r) = readln().split(' ')
        var nowNode:Node? = null

        tree.forEach{
            if(it.elem == e) {
                nowNode = it
            }
        }

        if(nowNode == null) {
            nowNode = Node(e)
            tree.add(nowNode!!)
        }

        var left:Node? = null
        var right:Node? = null

        if(l != ".") {
            left = Node(l)
            tree.add(left)
        }
        if(r != ".") {
            right = Node(r)
            tree.add(right)
        }

        nowNode?.left = left
        nowNode?.right = right
    }

    preOrderTraversal(tree[0])
    println()
    inOrderTraversal(tree[0])
    println()
    postOrderTraversal(tree[0])
}

fun preOrderTraversal(root: Node) {
    root.printNode()
    root.goLeft()?.let { preOrderTraversal(it) }
    root.goRight()?.let { preOrderTraversal(it) }
}

fun inOrderTraversal(root: Node) {
    root.goLeft()?.let { inOrderTraversal(it) }
    root.printNode()
    root.goRight()?.let { inOrderTraversal(it) }
}

fun postOrderTraversal(root: Node) {
    root.goLeft()?.let { postOrderTraversal(it) }
    root.goRight()?.let { postOrderTraversal(it) }
    root.printNode()
}
