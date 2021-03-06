//
//  PhysicsObject.h
//  CrazyBombman
//
//  Created by Yao Melo on 7/21/13.
//
//

#ifndef __CrazyBombman__PhysicsObject__
#define __CrazyBombman__PhysicsObject__

#include <iostream>
#include "cocos2d.h"
#include "Box2D.h"

namespace Simulation
{
    enum PhysicalType
    {
        PhysNone,
        PhysPlayer,
        PhysMob,
        PhysTerrain,
        PhysBomb,
        PhysExplosion,
    };
    
class PhysicsObject :public cocos2d::CCObject
{
private:
    b2Body* _body;
public:
    PhysicsObject():_body(0)
    {
        
    }
    
    b2Body* getBody()
    {
        return _body;
    }
    
    void setBody(b2Body* body);
    
    void initBody(b2World *_world);
    
    void clearBody(b2World*_world);
    
    virtual ~PhysicsObject();
    
    virtual PhysicalType getPhysicalType() {return PhysNone;};
    
    virtual void collideWith(PhysicsObject* other){};
    
    virtual bool acceptCollide(PhysicsObject* other){return true;};
    
protected:
    virtual b2Body* createBody(b2World *_world) {CC_UNUSED_PARAM(_world); return NULL; };
    

};
}
#endif /* defined(__CrazyBombman__PhysicsObject__) */
