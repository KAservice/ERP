#ifndef UREM_FormaElementaSprGrpHardwareCFH                  
#define UREM_FormaElementaSprGrpHardwareCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprGrpHardwareCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprGrpHardwareCF();                                                           
   ~TREM_FormaElementaSprGrpHardwareCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
