class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        w = width;
        h = height;
        m_food = food;
        score = 0;
        pos.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = pos.front(), tail = pos.back();
        pos.pop_back();
        if (direction == "U")
            --head.first;
        else if (direction == "D")
            ++head.first;
        else if (direction == "L")
            --head.second;
        else if (direction == "R")
            ++head.second;
        if (count(pos.begin(), pos.end(), head) || head.first < 0 || head.second < 0 || head.first >= h || head.second >= w) //h, w
            return -1;//this head is not in pos array yet!
        pos.insert(pos.begin(), head);
        if (!m_food.empty() && head == m_food.front()) { //eat the first food
            m_food.erase(m_food.begin()); //需要再想想erase的代价！！！！！！！！！！！！
            pos.push_back(tail);//get one more length, original tail pos
            ++score;
        }
        
        return score;
    }
    
    int w, h, score;
    vector<pair<int, int>> m_food, pos; //can use queue for food too
};
//由于蛇移动的过程的蛇头向前走一步，蛇尾也跟着往前，中间的躯体还在原来的位置，所以移动的结果就是，蛇头变到新位置，去掉蛇尾的位置即可
/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
