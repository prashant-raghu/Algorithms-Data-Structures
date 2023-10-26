class IntervalNode {
  constructor(start, end, data) {
    this.start = start;
    this.end = end;
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class IntervalTree {
  constructor() {
    this.root = null;
  }

  insert(start, end, data) {
    this.root = this._insert(this.root, start, end, data);
  }

  _insert(node, start, end, data) {
    if (node === null) {
      return new IntervalNode(start, end, data);
    }

    if (start < node.start) {
      node.left = this._insert(node.left, start, end, data);
    } else {
      node.right = this._insert(node.right, start, end, data);
    }

    return node;
  }

  search(number) {
    return this._search(this.root, number);
  }

  _search(node, number) {
    if (node === null) {
      return null;
    }

    if (number >= node.start && number <= node.end) {
      return node.data;
    }

    if (number < node.start) {
      return this._search(node.left, number);
    }

    return this._search(node.right, number);
  }
}
