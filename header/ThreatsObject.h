#pragma  once
#include "CommonFunc.h"
#include "bullet.h"

#define THREAT_FRAME_NUM 6
#define THREAT_SPEED 4

class ThreatsObject : public BaseObject{
    public:
        ThreatsObject();
        ~ThreatsObject();

        enum TypeMove{
            STATIC_THREAT = 0,
            ATTACK_THREAT = 1
        };

        void set_x_val(const float& xVal) { 
            x_val = xVal;
        }
        void set_y_val(const float& yVal){
            y_val = yVal;
        }
        void set_x_pos(const float& xPos){
            x_pos = xPos;
        }
         void set_y_pos(const float& yPos){
            y_pos = yPos;
        }
        float get_x_pos() const{
            return x_pos;
        }
        float get_y_pos() const{
            return y_pos;
        }

        void set_clips();
        bool LoadImg(std::string path, SDL_Renderer* screen);
        void Show(SDL_Renderer* des);
        int get_width_frame()const{
            return width_frame;
        }
        int get_height_frame() const{
            return height_frame;
        }
        void DoPlayer(Map& map_data);
        void CheckToMap(Map& map_data);

        void set_type_move(const int typeMove){
            type_move_ = typeMove;
        }
        void set_input_left(const int& ipLeft){
            input_type.left = ipLeft;
        }
        SDL_Rect GetRectFrame();

        std::vector<BulletObject*>get_bullet_list_() const{
            return bullet_list_;
        }

        void set_bullet_list(const std::vector <BulletObject*>& bl_list){
            bullet_list_ = bl_list;
        }

        void InitBullet(BulletObject* p_bullet, SDL_Renderer* screen);
        void MakeBullet(SDL_Renderer* screen, const int& x_limit, const int& y_limit);
        void RemoveBullet(const int& idx);
        
        Uint32 get_last_bullet() { return last_bullet; };
        void set_last_bullet(Uint32 l_b) { last_bullet = l_b; };
    private:
        float x_val;
        float y_val;

        float x_pos;
        float y_pos;

        bool on_ground;

        SDL_Rect frame_clip[THREAT_FRAME_NUM];
        
        int width_frame;
        int height_frame;
        int frame;

        int type_move_;
        Input input_type;

        Uint32 last_bullet = 0;

        std::vector<BulletObject*>bullet_list_;
};