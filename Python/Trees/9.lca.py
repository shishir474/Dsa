# Lowest Common Ancestor

def findLCA(root, p, q):
    if not root:
        return None
    if root.val == p.val or root.val == q.val:
        return root
    
    leftLCA = findLCA(root.left, p, q)
    rightLCA = findLCA(root.right, p, q)

    if leftLCA and rightLCA:
        return root
    elif leftLCA:
        return leftLCA
    else:
        return rightLCA
        