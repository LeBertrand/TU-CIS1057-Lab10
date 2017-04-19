package assign7_Shmuel_Jacobs;

/**
 * Interface to define a search tree
 * @author Koffman and Wolfgang
 **/
public interface SearchTree<E extends Comparable<E>>  {

    /**
     * Inserts item where it belongs in the tree.
     * @param item The item to be inserted
     * @return true If the item is inserted, false if the
     *         item was already in the tree.
     */
    boolean add(E item);

    /**
     * Determine if an item is in the tree
     * @param target Item being sought in tree
     * @return true If the item is in the tree, false otherwise
     */
    boolean contains(E target);

    /**
     * Find an object in the tree
     * @param target The item being sought
     * @return A reference to the object in the tree that compares
     *         equal as determined by compareTo to the target. If not found
     *         null is returned.
     */
    E find(E target);

    /**
     * Removes target from tree.
     * @param target Item to be removed
     * @return A reference to the object in the tree that compares
     * equal as determined by compareTo to the target. If not found
     * null is returned.
     * @post target is not in the tree
     */
    E delete(E target);

    /**
     * Removes target from tree.
     * @param target Item to be removed
     * @return true if the object was in the tree, false otherwise
     * @post target is not in the tree
     */
    boolean remove(E target);
}
#ifndef ALBUM_DATA_H
#define ALBUM_DATA_H

typedef struct{
    String title;
    String artist;
    String album;
    int seconds;
} song_t;

void selection_sort_category(song_t[] listing, int category, int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;
}

#endif ALBUM_DATA_H