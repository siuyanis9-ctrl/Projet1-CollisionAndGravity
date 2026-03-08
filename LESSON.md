PROJECT: Elastic Collision & Gravity Engine  
TIMELINE: Week 01 - One Project Every Week Challenge  
STATUS: Completed / Post-Mortem  

1. CHALLENGES ENCOUNTERED
The primary challenge of this project was translating abstract physical laws into functional computer logic.
- Gravity Implementation: Initially, I was unsure how to represent gravity programmatically. Through research, I learned that gravity is essentially a constant acceleration vector added to the velocity vector during each frame update.
- Collision Stability: My early versions were highly unstable. Objects would often overlap, vibrate, or phase through each other upon impact.

2. KEY TECHNICAL IMPROVEMENTS
- Static Resolution (Overlap Correction): This was the most critical fix developed during the process. In previous iterations, if two objects moved too close, they would "stick" together. Implementing the Overlap Resolution function allowed for physical separation of the entities before calculating their new velocities, ensuring a smooth simulation.
- Normal Vector Impulse: Moving away from simple sign inversion to a system based on Normal Vectors and Impulse (Pulse) calculations significantly improved the realism of the bounces. The physics now respect the angles of impact rather than just basic axis flipping.

3. CODE EVOLUTION & REFINEMENT
- Warning Elimination: Transitioning from a codebase filled with compiler warnings to a "Zero Warning" state required a deeper understanding of type safety. I implemented explicit casts between float, int, and Uint8 to ensure the logic was robust across different compilers.
- Modular Structure: Refactoring the monolithic code into dedicated headers (ball.hpp, physic.hpp) improved maintainability and followed better software engineering standards.

4. CONCLUSION
This project demonstrated that coding physics is not just about formulas, but about handling "visual artifacts" like object interpenetration. This first week has successfully satisfied my intellectual curiosity regarding 2D simulations while reinforcing my coding discipline regarding types and memory safety.
