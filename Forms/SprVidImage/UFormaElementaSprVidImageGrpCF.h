#ifndef UFormaElementaSprVidImageGrpCFH                  
#define UFormaElementaSprVidImageGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprVidImageGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprVidImageGrpCF();                                                           
   ~TFormaElementaSprVidImageGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
