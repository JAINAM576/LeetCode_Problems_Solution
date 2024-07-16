/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.HashMap;
import java.util.Map;

class Solution {
    private TreeNode node = null;
    
    private void findNode(TreeNode root, int val) {
        if (root == null) return;
        if (node != null) return;
        if (root.val == val) {
            node = root;
            return;
        }
        findNode(root.left, val);
        findNode(root.right, val);
    }

    private boolean getsrc(TreeNode root, int val, Map<Integer, int[]> mp, int[] findMax) {
        if (root == null) return false;
        if (root.val == val) return true;

        boolean a = getsrc(root.left, val, mp, findMax);
        boolean b = getsrc(root.right, val, mp, findMax);
        int[] valArr = mp.getOrDefault(root.val, new int[]{0, 0});
        valArr[0] = a ? 2 : (valArr[0] == 0 ? 0 : valArr[0]);
        valArr[0] = b ? 1 : (valArr[0] == 0 ? 0 : valArr[0]);
        mp.put(root.val, valArr);

        findMax[0] = Math.max(findMax[0], root.val);
        return a || b;
    }

    private boolean getdesti(TreeNode root, int val, Map<Integer, int[]> mp, int[] findMax) {
        if (root == null) return false;
        if (root.val == val) return true;

        boolean a = getdesti(root.left, val, mp, findMax);
        boolean b = getdesti(root.right, val, mp, findMax);
        int[] valArr = mp.getOrDefault(root.val, new int[]{0, 0});
        valArr[1] = a ? 2 : (valArr[1] == 0 ? 0 : valArr[1]);
        valArr[1] = b ? 1 : (valArr[1] == 0 ? 0 : valArr[1]);
        mp.put(root.val, valArr);

        findMax[0] = Math.max(findMax[0], root.val);
        return a || b;
    }

    private void up(TreeNode root, StringBuilder s, int val, Map<Integer, int[]> src) {
        if (root == null) return;

        if (root.left != null &&src.getOrDefault(root.val, new int[]{0, 0})[0] == 2) {
            s.append('U');
            up(root.left, s, val, src);
        }
        if (root.right != null &&src.getOrDefault(root.val, new int[]{0, 0})[0] == 1) {
            s.append('U');
            up(root.right, s, val, src);
        }
    }

    private void down(TreeNode root, StringBuilder s, int val, Map<Integer, int[]> src) {
        if (root == null) return;

        if (root.left != null &&src.getOrDefault(root.val, new int[]{0, 0})[1] == 2) {
            s.append('L');
            down(root.left, s, val, src);
        }
        if (root.right != null && src.getOrDefault(root.val, new int[]{0, 0})[1] == 1) {
            s.append('R');
            down(root.right, s, val, src);
        }
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        Map<Integer, int[]> src = new HashMap<>();
        int[] findMax = new int[]{-1};

        getsrc(root, startValue, src, findMax);
        getdesti(root, destValue, src, findMax);
        int n = findMax[0];
        StringBuilder ans = new StringBuilder();

        for (int i = 1; i <= n; i++) {
            if ((src.getOrDefault(i, new int[]{0, 0})[0] == 1 && src.getOrDefault(i, new int[]{0, 0})[1] == 2) ||
                (src.getOrDefault(i, new int[]{0, 0})[0] == 2 && src.getOrDefault(i, new int[]{0, 0})[1] == 1)) {
                findNode(root, i);
                up(node, ans, startValue, src);
                down(node, ans, destValue, src);
                break;
            } else if (i == startValue && (src.getOrDefault(i, new int[]{0, 0})[1] != 0)) {
                findNode(root, i);
                down(node, ans, destValue, src);
                break;
            } else if (i == destValue && (src.getOrDefault(i, new int[]{0, 0})[0] != 0)) {
                findNode(root, i);
                up(node, ans, startValue, src);
                break;
            }
        }
        return ans.toString();
    }
}
