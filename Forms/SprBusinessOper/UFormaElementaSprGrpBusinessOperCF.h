#ifndef UFormaElementaSprGrpBusinessOperCFH                  
#define UFormaElementaSprGrpBusinessOperCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprGrpBusinessOperCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprGrpBusinessOperCF();                                                           
   ~TFormaElementaSprGrpBusinessOperCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
