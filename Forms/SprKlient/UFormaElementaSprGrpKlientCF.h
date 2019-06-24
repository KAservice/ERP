#ifndef UFormaElementaSprGrpKlientCFH                  
#define UFormaElementaSprGrpKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprGrpKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprGrpKlientCF();                                                           
   ~TFormaElementaSprGrpKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
