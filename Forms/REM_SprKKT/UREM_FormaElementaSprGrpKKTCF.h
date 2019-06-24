#ifndef UREM_FormaElementaSprGrpKKTCFH                  
#define UREM_FormaElementaSprGrpKKTCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprGrpKKTCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprGrpKKTCF();                                                           
   ~TREM_FormaElementaSprGrpKKTCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
