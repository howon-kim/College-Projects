/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Lab 8.1
 * @author HWKIM
 */
public class ListNode {
    private String data;
    private ListNode link;

    public ListNode() {
        link = null;
        data = null;
    }

    public ListNode(String newData, ListNode linkValue) {
        data = newData;
        link = linkValue;
    }

    public void setData(String newData) {
        data = newData;
    }

    public String getData() {
        return data;
    }

    public void setLink(ListNode newLink) {
        link = newLink;
    }

    public ListNode getLink() {
        return link;
    }
}
