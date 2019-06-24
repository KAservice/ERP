#ifndef UREM_FormaElementaSprHardwareCFH                  
#define UREM_FormaElementaSprHardwareCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprHardwareCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprHardwareCF();                                                           
   ~TREM_FormaElementaSprHardwareCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
