#ifndef UFormaSpiskaSprGrpKlientCFH                  
#define UFormaSpiskaSprGrpKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprGrpKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprGrpKlientCF();                                                           
   ~TFormaSpiskaSprGrpKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
