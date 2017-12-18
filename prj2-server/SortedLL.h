#pragma once
#include "Node.h"
#include <iostream>

#ifndef _SORTED_LINKED_LIST_H
#define _SORTED_LINKED_LIST_H

/**
*	������ ������ ���� ���ĵ� ��ũ�� ����Ʈ
*/
template <typename T>
class SortedLL
{
public:

	/**
	*	�⺻ ������
	*/
	SortedLL();

	/**
	*	�Ҹ���
	*/
	~SortedLL();

	/**
	*	@brief	����Ʈ�� �� ���·� �ʱ�ȭ ��Ų��.
	*	@pre	����.
	*	@post	����Ʈ�� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� �����ϴ� ����� ���� �����´�.
	*	@pre	����.
	*	@post	�Լ� �� = ����Ʈ�� �ִ� ����� ��.
	*	@return	����Ʈ�� �ִ� ����� ��.
	*/
	int GetLength() const;

	/**
	*	@brief	����Ʈ�� ���ĵ� ��ġ�� item�� �߰�.
	*	@pre	����Ʈ�� ���� ���� �ʾƾ���, ����Ʈ�� item�� ���� �߰� ���� ����.
	*	@post	item�� ����Ʈ�� �߰���.
	*/
	void Add(T item);

	/**
	*	@brief	item�� Ű�� ��ġ�ϴ� Ű�� ������ ����Ʈ�� �����͸� ����(�ִٸ�).
	*	@pre	����Ʈ�� ������� �ʾƾ���, ����Ʈ�� �������� ���� ���� ���� ����.
	*	@post	�����Ͱ� ����Ʈ���� ���� �ǰ�, item�� �����.
	*/
	void Delete(T& item);

	/**
	*	@brief	����Ʈ�� �ִ� item�� �����͸� �ٲ۴�.
	*	@pre	����Ʈ�� ������� �ʰ�, �ٲٰ��� �ϴ� �������� ����Ʈ�� ����.
	*	@post	item�� �����Ͱ� �����.
	*	@return	�Լ��� ����� �۵��ϸ� 1 ��ȯ �� �ܿ��� 0 ��ȯ.
	*/
	int Replace(T item);

	/**
	*	@brief	item�� Ű�� ��ġ�ϴ� Ű�� ������ ����Ʈ�� �����͸� ��ȯ(�ִٸ�).
	*	@pre	item�� Ű ����� ���� �Ǿ��־����.
	*	@post	item�� Ű�� ��ġ�ϴ� ����Ʈ�� �����͸� item�� ����.
	*	@return	���������� �����͸� ã�Ҵٸ� 1 ��ȯ, �� �ܿ��� 0 ��ȯ.
	*/
	int Get(T& item);

	/**
	*	@brief	����Ʈ�� ���ͷ����� curPtr�� �ʱ�ȭ.
	*	@pre	����.
	*	@post	curPtr�� �ʱ�ȭ ��.
	*/
	void ResetList();

	/**
	*	@brief	����Ʈ �� ���� ��ġ�� �ִ� ��忡 ����.
	*	@pre	curPtr�� ���ǵǾ� �ְ�, curPtr�� ����Ʈ�� ������ ��带 ����Ű�� ���� ����.
	*	@post	curPtr�� ���� ��带 ����Ű�� �ְ�, item�� �� ��带 ������.
	*/
	void GetNextItem(T& item);

private:

	NodeType<T>* m_List;	///< ����Ʈ�� ù ��带 ����Ű�� ������
	NodeType<T>* m_curPtr;	///< ����Ʈ���� ���� �����ϰ� �ִ� ���
	int length;				///< ����Ʈ�� �ִ� ����� ��
};

// �⺻ ������
template <typename T>
SortedLL<T>::SortedLL()
{
	length = 0;
	m_List = NULL;
	m_curPtr = NULL;
}


// �Ҹ���
template <typename T>
SortedLL<T>::~SortedLL()
{
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// ����Ʈ�� �� ���·� �ʱ�ȭ
template <typename T>
void SortedLL<T>::MakeEmpty()
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_List != NULL)
	{
		tempPtr = m_List;
		m_List = m_List->next;
		delete tempPtr;
	}

	length = 0;
}


// ����Ʈ�� �ִ� ����� �� ��ȯ
template <typename T>
int SortedLL<T>::GetLength() const
{
	return length;
}


// ����Ʈ�� ������ �߰�
template <typename T>
void SortedLL<T>::Add(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T temp;
	bool found = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list�� node�� �������� �ʴ� ���
	if (!length)
		m_List = node;

	// list�� node�� �ϳ� �̻� �����ϴ� ���
	else
	{
		m_curPtr = m_List;

		while (!found)
		{
			// node�� data�� curPtr�� data ���� �۴� 
			if (node->data < m_curPtr->data)
			{
				found = true;

				// node�� ����Ʈ�� �� �տ� �߰�
				if (m_curPtr->data == m_List->data)
					m_List = node;
				// node�� ����Ʈ�� �߰��� �߰�
				else
					pre->next = node;

				node->next = m_curPtr;
			}
			else
			{
				// node�� ����Ʈ�� �������� �߰�
				if (m_curPtr->next == NULL)
				{
					m_curPtr->next = node;
					break;
				}
				pre = m_curPtr;
				GetNextItem(temp);
			}
		}
	}
	// ���� 1 ����
	length++;
}

// ����Ʈ���� ��� ����
template <typename T>
void SortedLL<T>::Delete(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;
	NodeType<T>* pre;

	location = m_List;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;

			if (location->data == m_List->data)
				m_List = location->next;
			else
				pre->next = location->next;

			delete location;
		}
		else
		{
			pre = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
	length--;
}

// ����Ʈ�� �ִ� item�� �����͸� �ٲ۴�
template <typename T>
int SortedLL<T>::Replace(T item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����
	location = m_List;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}
	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

// item�� Ű�� ��ġ�ϴ� Ű�� ������ ����Ʈ�� �����͸� ��ȯ(�ִٸ�)
template <typename T>
int SortedLL<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_List;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}


// ����Ʈ�� ���ͷ����� curPtr�� �ʱ�ȭ
template <typename T>
void SortedLL<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_curPtr = NULL;
}


// ����Ʈ �� ���� ��ġ�� �ִ� ��忡 ����
template <typename T>
void SortedLL<T>::GetNextItem(T& item)
{
	// curPtr�� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_curPtr == NULL)
	{
		m_curPtr = m_List;
	}
	else
		//curPtr�� ���� ���� �̵�
		m_curPtr = m_curPtr->next;

	//item �� curPtr�� info �� ����
	item = m_curPtr->data;
}

#endif	// SORTED_LINKED_LIST